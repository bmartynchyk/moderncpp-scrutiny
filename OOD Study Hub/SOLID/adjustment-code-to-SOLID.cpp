
#include "adjustment-code-to-SOLID.h"

#include <iostream>

// How to adjust code to SOLID principles?
//class IOManager {
//public:
//	void SaveToFile(const std::string& filePath);
//	void ReadFromFile(const std::string& filePath);

//	void SaveToDB(const std::string& url);
//	void ReadFromDB(const std::string& url);

//	void SaveToServer(const std::string& url);
//	void ReadFromServer(const std::string& url);
//};


// This is godlike object.
// Step #1
//class FileManager {
// public:
//	void SaveToFile(const std::string& filePath);
//	void ReadFromFile(const std::string& filePath);
//};

//class DBManager {
// public:
//	void SaveToDB(const std::string& url);
//	void ReadFromDB(const std::string& url);
//};

//class DBServer {
// public:
//	void SaveToServer(const std::string& url);
//	void ReadFromServer(const std::string& url);
//};

//Step #2
class IManager {
public:
	virtual void Save(const std::string& url);
	virtual void Read(const std::string& url);
};

class FileManager: IManager {
public:
	virtual void Save(const std::string& filePath) override;
	virtual void Read(const std::string& filePath) override;
};

class DBManager: IManager {
public:
	virtual void Save(const std::string& url) override;
	virtual void Read(const std::string& url) override;
};

class DBServer: IManager {
public:
	virtual void Save(const std::string& url) override;
	virtual void Read(const std::string& url) override;
};
