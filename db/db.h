#ifndef DB_H
#define DB_H

#include <mutex>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "dirent.h"

class DB{
public:
  DB(std::string _path, std::string _fileEnding = ".db");
  ~DB();

  // getEncounters
  // Get all encounters of an contact person
  // Input:
  //  puplicKeyContactPerson - puplic key of the contact person which wants to know its encounters
  // Return: vector of all encounters. Each entry containing a tuple of 
  //   puplicKeyContactPerson	std::string
  //   puplicKeyInfectedPerson	std::string
  //   coordinates longitude	double
  //   coordinate altitude		double
  //   timestamp [ms]			UINT64
  std::vector<std::tuple<std::string,std::string,double,double, UINT64>>  getEncounters(std::string puplicKeyContactPerson);

  // getEncounters
  // Submit all encounters of an infected person
  // Input:
  //  vector of all encounters. Each entry containing a tuple of 
  //   puplicKeyContactPerson	std::string
  //   puplicKeyInfectedPerson	std::string
  //   coordinates longitude	double
  //   coordinate altitude		double
  //   timestamp [ms]			UINT64
  void submitEncounters(std::vector<std::tuple<std::string, std::string, double, double, UINT64>>);


private:
  std::vector<std::string> splitString(std::string _stringToBeSplitted, std::string _delimeter);
  std::string getFilenameOfContact(std::string _puplicKeyOfContactPerson);

  std::string m_path;
  std::string m_fileEnding;
  std::mutex mtx;
};

#endif // DB_H
