#include "DirectAccessFile.h"

void printHeader()
{
	cout << endl << "| Index | ID |         Name         | Mobile Number | Chain |";
}

void printLine()
{
	cout << endl << "-------------------------------------------------------------";
}

void printRecord(Employee emp,int i)
{
	cout << endl << "| " << setw(5) << i << " | " << setw(2) << emp.id << " | " << setw(20) << emp.name << " | " << setw(13) << emp.mobile << " | " << setw(5) << emp.chain << " |";
}

DirectAccessFile::DirectAccessFile(int _size)
{
	int i = 0;
	size = _size;
	file.open("data.dat", ios::out | ios::trunc | ios::binary);
	emp.init();
	for (i = 0; i < size; i++)
	{
		file.write((char*)(&emp), sizeof(emp));
	}
	file.close();
}

int DirectAccessFile::hash(int key)
{
	return (key%size);
}

void DirectAccessFile::display()
{
	file.open("data.dat", ios::in | ios::binary);
	if (file)
	{
		printLine();
		printHeader();
		printLine();
		for (int i = 0; i < size; i++)
		{
			if (file.read((char*)(&emp), sizeof(emp)))
				printRecord(emp,i);
			printLine();

		}
	}
	cout << endl << endl;
	file.close();
}

void DirectAccessFile::insert()
{
	Employee temp;
	int index = 0, i = 0;
	long int chainLocation = -1;
	file.open("data.dat", ios::out | ios::binary | ios::in);
	emp.get();
	i = index = hash(emp.id);
	file.seekg(i * sizeof(Employee), ios::beg);
	file.read((char *)&temp, sizeof(Employee));
		i = hash(i + 1);
	while (i != index)
	{
		file.seekg(i * sizeof(Employee), ios::beg);
		file.read((char *)&temp, sizeof(Employee));
		if (hash(temp.id) == index)
			break;
		i = hash(i + 1);
	}
	file.seekg(i * sizeof(Employee), ios::beg);
	file.read((char *)&temp, sizeof(Employee));
	if (hash(temp.id) == index)
	{
		while (temp.chain != -1)
		{
			i = temp.chain;
			file.seekg(i * sizeof(Employee), ios::beg);
			file.read((char *)&temp, sizeof(Employee));
		}
		chainLocation = i;
	}
	while (temp.id != -1)
	{
		i = hash(i + 1);
		file.seekg(i * sizeof(Employee), ios::beg);
		file.read((char *)&temp, sizeof(Employee));
	}
	file.seekp(i * sizeof(Employee), ios::beg);
	file.write((char *)&emp, sizeof(Employee));
	if (chainLocation != -1)
	{
		file.seekg(chainLocation * sizeof(Employee), ios::beg);
		file.read((char *)&temp, sizeof(Employee));
		temp.chain = i;
		file.seekp(chainLocation * sizeof(Employee), ios::beg);
		file.write((char *)&temp, sizeof(Employee));
	}
	file.close();
}

bool DirectAccessFile::search(int key)
{
	int i = hash(key), index = i;
	file.open("data.dat", ios::out | ios::binary | ios::in);
	file.seekg(i * sizeof(Employee), ios::beg);
	if (file.read((char *)&emp, sizeof(Employee)))
		cout << "yes";
	else
		cout << "no";
	if (emp.id == key)
	{
		cout << endl << "record found";
		file.close();
		return true;
	}
	else
	{
		i = hash(i + 1);
		file.seekg(i * sizeof(Employee), ios::beg);
		file.read((char *)&emp, sizeof(Employee));
		while (hash(emp.id) != index)
		{
			i = hash(i + 1);
			file.seekg(i * sizeof(Employee), ios::beg);
			file.read((char *)&emp, sizeof(Employee));
			if (i == index)
				break;
		}
		if (i == index)
		{
			cout << endl << "Record not found";
			file.close();
			return false;
		}
		else
		{
			while (emp.chain != -1)
			{
				if (emp.id == key)
				{
					cout << "Record found at position: " << i;
					file.close();
					return true;
				}
				i = emp.chain;
				file.seekg(i * sizeof(Employee), ios::beg);
				file.read((char *)&emp, sizeof(Employee));
			}
			if (emp.id == key)
			{
				cout << "Record found at position: " << i;
				file.close();
				return true;
			}
			else
			{
				cout << "Record not found";
				file.close();
				return false;
			}
		}
	}
	file.close();
}

void DirectAccessFile::modify(int key)
{
	int i = hash(key), index = i;
	file.open("data.dat", ios::out | ios::binary | ios::in);
	file.seekg(i * sizeof(Employee), ios::beg);
	file.read((char *)&emp, sizeof(Employee));
	if (emp.id == key)
	{
		cout << endl << "Following record found:" << endl;
		printLine();
		printHeader();
		printLine();
		printRecord(emp, i);
		printLine();
		cout << endl << "Enter new details of record:";
		emp.get();
		file.seekp(i * sizeof(Employee), ios::beg);
		file.write((char *)&emp, sizeof(Employee));
	}
	else
	{
		i = hash(i + 1);
		file.seekg(i * sizeof(Employee), ios::beg);
		file.read((char *)&emp, sizeof(Employee));
		while (hash(emp.id) != index)
		{
			i = hash(i + 1);
			file.seekg(i * sizeof(Employee), ios::beg);
			file.read((char *)&emp, sizeof(Employee));
			if (i == index)
				break;
		}
		if (i == index)
			cout << endl << "Record not found";
		else
		{
			while (emp.chain != -1)
			{
				if (emp.id == key)
				{
					cout << endl << "Following record found:" << endl;
					printLine();
					printHeader();
					printLine();
					printRecord(emp, i);
					printLine();
					cout << endl << "Enter new details of record:";
					emp.get();
					file.seekp(i * sizeof(Employee), ios::beg);
					file.write((char *)&emp, sizeof(Employee));
					file.close();
					return;
				}
				i = emp.chain;
				file.seekg(i * sizeof(Employee), ios::beg);
				file.read((char *)&emp, sizeof(Employee));
			}
			if (emp.id == key && emp.chain == -1)
			{
				cout << endl << "Following record found:" << endl;
				printLine();
				printHeader();
				printLine();
				printRecord(emp, i);
				printLine();
				cout << endl << "Enter new details of record:";
				emp.get();
				file.seekp(i * sizeof(Employee), ios::beg);
				file.write((char *)&emp, sizeof(Employee));
			}
			else
				cout << "Record not found";
		}
	}
	file.close();
	cout << endl << "File after modification is: ";
	this->display();
}

void DirectAccessFile::deleter(int key)
{
	int i = hash(key), index = i,temp=0;
	file.open("data.dat", ios::out | ios::binary | ios::in);
	file.seekg(i * sizeof(Employee), ios::beg);
	file.read((char *)&emp, sizeof(Employee));
	if (emp.id == key)
	{
		cout << endl << "record found";
		if (emp.chain != -1)
		{
			temp = emp.chain;
			file.seekg(emp.chain * sizeof(Employee), ios::beg);
			file.read((char *)&emp, sizeof(Employee));
			file.seekp(i * sizeof(Employee), ios::beg);
			file.write((char *)&emp, sizeof(Employee));
			file.seekp(temp * sizeof(Employee), ios::beg);
			emp.init();
			file.write((char *)&emp, sizeof(Employee));
		}
		else
		{
			file.seekp(i * sizeof(Employee), ios::beg);
			emp.init();
			file.write((char *)&emp, sizeof(Employee));
		}
	}
	else
	{
		i = hash(i + 1);
		file.seekg(i * sizeof(Employee), ios::beg);
		file.read((char *)&emp, sizeof(Employee));
		while (hash(emp.id) != index)
		{
			i = hash(i + 1);
			file.seekg(i * sizeof(Employee), ios::beg);
			file.read((char *)&emp, sizeof(Employee));
			if (i == index)
				break;
		}
		if (i == index)
		{
			cout << endl << "Record not found";
		}
		else
		{
			while (emp.chain != -1)
			{
				if (emp.id == key)
				{
					cout << "Record found at position: " << i;
					if (emp.chain != -1)
					{
						temp = emp.chain;
						file.seekg(emp.chain * sizeof(Employee), ios::beg);
						file.read((char *)&emp, sizeof(Employee));
						file.seekp(i * sizeof(Employee), ios::beg);
						file.write((char *)&emp, sizeof(Employee));
						file.seekp(temp * sizeof(Employee), ios::beg);
						emp.init();
						file.write((char *)&emp, sizeof(Employee));
					}
					else
					{
						file.seekp(i * sizeof(Employee), ios::beg);
						emp.init();
						file.write((char *)&emp, sizeof(Employee));
					}
				}
				i = emp.chain;
				file.seekg(i * sizeof(Employee), ios::beg);
				file.read((char *)&emp, sizeof(Employee));
			}
			if (emp.id == key && emp.chain == -1)
			{
				cout << "Record found at position: " << i;
				if (emp.chain != -1)
				{
					temp = emp.chain;
					file.seekg(emp.chain * sizeof(Employee), ios::beg);
					file.read((char *)&emp, sizeof(Employee));
					file.seekp(i * sizeof(Employee), ios::beg);
					file.write((char *)&emp, sizeof(Employee));
					file.seekp(temp * sizeof(Employee), ios::beg);
					emp.init();
					file.write((char *)&emp, sizeof(Employee));
				}
				else
				{
					file.seekp(i * sizeof(Employee), ios::beg);
					emp.init();
					file.write((char *)&emp, sizeof(Employee));
				}
			}
			else
			{
				cout << "Record not found";
			}
		}
	}
	file.close();
	this->display();
}

DirectAccessFile::~DirectAccessFile()
{

}

