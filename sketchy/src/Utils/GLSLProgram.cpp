
#include<sketchy_config.h>
#include<GLSLProgram.h>

GLSLProgram::GLSLProgram()
	: mHandle(-1)
	, mIsLinked(false)
{
	mShaderHandles = new GLuint[GLSLShader::eST_Count];
	mShaderHandles = { 0 };
}

GLSLProgram::~GLSLProgram()
{
	delete[] mShaderHandles;
}

void GLSLProgram::CompileShader(const char * aFilename) const
{
	//@todo
}

void GLSLProgram::CompileShader(const char * aFilename, GLSLShader::EGLSLShaderType aShaderType) const
{
	//@todo
}

bool GLSLProgram::CompileShader(const char* aSource, GLSLShader::EGLSLShaderType aShaderType, const char * aFilename) const
{
	//@todo add assert
	GLuint lShader = glCreateShader(aShaderType);
	glShaderSource(lShader, 1, &aSource, NULL);
	glCompileShader(lShader);

	GLint lIsCompiled = 0;
	glGetShaderiv(lShader, GL_COMPILE_STATUS, &lIsCompiled);
	if (GL_FALSE == lIsCompiled)
	{
		GLint maxLength = 0;
		glGetShaderiv(lShader, GL_INFO_LOG_LENGTH, &maxLength);

		GLchar* lErrorLog = new GLchar[maxLength];

		glGetShaderInfoLog(lShader, maxLength, &maxLength, lErrorLog);
		char lBuff[1024];
		sprintf(lBuff, " Compilation shader errors: %d", 1);
		printf(lBuff);
		LogConsoleString(" Compilation shader errors: %d", 1);
		LogConsoleString(lErrorLog);

		delete[] lErrorLog;

		return false;
	}

	mShaderHandles[aShaderType] = lShader;

	return true;
}

void GLSLProgram::Link() const
{
	//@TODO
}

void GLSLProgram::UseProgram() const
{
	//@TODO
}

void GLSLProgram::Validate() const
{
	//@TODO
}

void GLSLProgram::BindAttribLocation(GLuint aLocation, const char * aName) const
{
	//@TODO
}

void GLSLProgram::BindFragDataLocation(GLuint aLocation, const char * aName) const
{
	//@TODO
}

void GLSLProgram::SetUniform(const char *aName, float aX, float aY, float aZ)
{
	//@TODO
}

void GLSLProgram::SetUniform(const char *aName, const glm::vec3 & aVec3)
{
	//@TODO
}

void GLSLProgram::SetUniform(const char *aName, const glm::vec4 & aVec4)
{
	//@TODO
}

void GLSLProgram::SetUniform(const char *aName, const glm::mat3 & aMat3)
{
	//@TODO
}

void GLSLProgram::SetUniform(const char *aName, const glm::mat4 & aMat4)
{
	//@TODO
}

void GLSLProgram::SetUniform(const char *aName, float aVal)
{
	//@TODO
}

void GLSLProgram::SetUniform(const char *aName, int   aVal)
{
	//@TODO
}

void GLSLProgram::SetUniform(const char *aName, bool  aVal)
{
	//@TODO
}

void GLSLProgram::PrintActiveUniforms() const
{
	//@TODO
}

void GLSLProgram::PrintActiveAttribs() const
{
	//@TODO
}

void GLSLProgram::PrintActiveUniformBlocks() const
{
	//@TODO
}

int GLSLProgram::GetUniformLocation(const char * aName) const
{
	//@TODO
	return -1;
}
