#define _CRT_SECURE_NO_WARNINGS

#include "util1.hpp"
#include "data1.hpp"
#include "cloud.hpp"

#define BACKUP_FILE "./backup.dat"
#define BACKUP_DIR "./backup/"
int main()
{
	//cloud::FileUtil fu("./");
	//std::vector<std::string> arry;
	//fu.ScanDirectory(&arry);
	//cloud::DateManager data(BACKUP_FILE);
	//for (auto& a : arry)
	//{
	//	data.Insert(a, "af");
	//	//std::cout << a << std::endl;
	//}
	cloud::Backup backup(BACKUP_DIR, BACKUP_FILE);
	backup.Runmodule();
	return 0;
}