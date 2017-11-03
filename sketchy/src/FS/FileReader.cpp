
#include<sketchy_config.h>
#include<FileReader.h>

#include <string>
#include <fstream>
#include <streambuf>

FileReader::FileReader(const std::string& aPath, const std::string& aFileName)
	: mPath		(aPath)
	, mFileName	(aFileName)
{

}

bool FileReader::ReadFile()
{
    assert(!mFileName.empty());
    if (!mFileName.empty())
    {
        std::ifstream lStream(mPath + mFileName);

        if (!lStream.fail())
        {
            mStr.assign(std::istreambuf_iterator<char>(lStream), std::istreambuf_iterator<char>());
            return true;
        }
        else
        {
            LogConsoleString("Failed to read '%s' in path '%s'", mFileName.c_str(), mPath.c_str());
        }

        lStream.close();
    }

	return false;
}