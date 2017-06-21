#include<GLSLProgram.h>

GLSLProgram::GLSLProgram()
	: mHandle(-1)
	, mIsLinked(false)
{
}

void GLSLProgram::CompileShader(const char * aFilename) const
{
	//@todo
}

void GLSLProgram::CompileShader(const char * aFilename, GLSLShader::GLSLShaderType aShaderType) const
{
	//@todo
}

void GLSLProgram::CompileShader(const std::string& aSource, GLSLShader::GLSLShaderType aShaderType, const char * aFilename) const
{
	//@TODO
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
