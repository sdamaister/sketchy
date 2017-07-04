
#include<sketchy_config.h>
#include<GLSLProgram.h>

GLSLProgram::GLSLProgram()
	: mIsLinked(false)
{
	mProgramHandle = glCreateProgram();
}

void GLSLProgram::CompileShader(const char * aFilename)
{
	//@todo
}

void GLSLProgram::CompileShader(const char * aFilename, GLSLShader::EGLSLShaderType aShaderType)
{
	//@todo
}

bool GLSLProgram::CompileShader(const char* aSource, GLSLShader::EGLSLShaderType aShaderType, const char * aFilename)
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
		const char* lShaderTypeStr = "Vertex Shader";
		
		/*char lBuff[1024] = { 0 };
		sprintf_s(lBuff, "\n%s compilation error:", GetShaderTypeString(aShaderType));*/
		LogConsoleString("\n%s compilation error:", GetShaderTypeString(aShaderType));
		LogConsoleString(lErrorLog);

		delete[] lErrorLog;

		return false;
	}

	mShaderHandles[aShaderType] = lShader;

	return true;
}

bool GLSLProgram::Link()
{
	for (int i = 0; i < GLSLShader::eST_Count; ++i)
	{
		if (mShaderHandles[i])
		{
			glAttachShader(mProgramHandle, mShaderHandles[i]);
		}
	}

	glLinkProgram(mProgramHandle);

	GLint status;
	glGetProgramiv(mProgramHandle, GL_LINK_STATUS, &status);
	if (GL_FALSE == status) {
		fprintf(stderr, "Failed to link shader program!\n");
		GLint logLen;

		glGetProgramiv(mProgramHandle, GL_INFO_LOG_LENGTH,
			&logLen);
		if (logLen > 0)
		{
			char * log = new char[logLen];
			GLsizei written;
			glGetProgramInfoLog(mProgramHandle, logLen, &written, log);
			fprintf(stderr, "Program log: \n%s", log);
			LogConsoleString("Program log: \n%s", log);

			delete[] log;

			mIsLinked = false;
		}
	}
	else
	{
		mIsLinked = true;
	}

	return mIsLinked;
}

void GLSLProgram::UseProgram() const
{
	if (mProgramHandle)
	{
		glUseProgram(mProgramHandle);
	}
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

const char* GLSLProgram::GetShaderTypeString(GLSLShader::EGLSLShaderType aShaderType)
{
	switch (aShaderType)
	{
	case GLSLShader::eST_Vertex:
		return "Vertex shader";
	case GLSLShader::eST_Fragment:
		return "Fragment shader";
	case GLSLShader::eST_Geometry:
		return "Geometry shader";
		/*case GLSLShader::eST_TessControl:
		break;
		case GLSLShader::eST_TessEvaluation:
		break;
		case GLSLShader::eST_Compute:
		break;*/
	default:
		break;
	}

	return 0;
}