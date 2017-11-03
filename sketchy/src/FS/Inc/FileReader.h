/*
@class	GLSLProgram
*/

#ifndef __SKETCHY_FILEREADER__
#define __SKETCHY_GLSLPROGRAM__

class FileReader
{
public:

	FileReader(const std::string& aPath, const std::string& aFileName);
	
	bool ReadFile();	
	
	std::string& GetPath	() { return mPath;	   }
	std::string& GetFileName() { return mFileName; }
	std::string& GetStr		() { return mStr;	   }

private:

	std::string mPath;
	std::string mFileName;
	std::string mStr;
};

#endif // __SKETCHY_GLSLPROGRAM__
