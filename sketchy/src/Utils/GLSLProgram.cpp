#include<GLSLProgram.h>

GLSLProgram::GLSLProgram()
	: mHandle(-1)
	, mLinked(false)
{
}

void GLSLProgram::CompileShader(const char * aFilename)
{
	//@todo
}

void GLSLProgram::CompileShader(const char * aFilename, GLSLShader::GLSLShaderType aShaderType)
{
	//@todo
}

void GLSLProgram::CompileShader(const std::string& aSource, GLSLShader::GLSLShaderType aShaderType, const char * aFilename = NULL)
{
	//@TODO
}

void GLSLProgram::Link()
{
	//@TODO
}

void GLSLProgram::UseProgram()
{
	//@TODO
}

void GLSLProgram::Validate()
{
	//@TODO
}

int	GLSLProgram::GetHandle()
{
	//@TODO
}

bool GLSLProgram::IsLinked()
{
	//@TODO
}

void GLSLProgram::BindAttribLocation(GLuint aLocation, const char * aName)
{
	//@TODO
}

void GLSLProgram::BindFragDataLocation(GLuint aLocation, const char * aName)
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

void GLSLProgram::PrintActiveUniforms()
{
	//@TODO
}

void GLSLProgram::PrintActiveAttribs()
{
	//@TODO
}

void GLSLProgram::PrintActiveUniformBlocks()
{
	//@TODO
}

int GLSLProgram::GetUniformLocation(const char * aName)
{
	//@TODO
}