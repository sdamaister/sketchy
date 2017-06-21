/*
@class	CShader
*/

#ifndef __SKETCHY_GLSLPROGRAM__
#define __SKETCHY_GLSLPROGRAM__

#include<stdexcept>
#include<string>
#include<map>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

namespace GLSLShader
{
	enum GLSLShaderType
	{
		VERTEX			= GL_VERTEX_SHADER,
		FRAGMENT		= GL_FRAGMENT_SHADER,
		GEOMETRY		= GL_GEOMETRY_SHADER,
		/* @todo: investigate where are defined
		TESS_CONTROL	= GL_TESS_CONTROL_SHADER,
		TESS_EVALUATION = GL_TESS_EVALUATION_SHADER,
		COMPUTE			= GL_COMPUTE_SHADER*/
	};
};

class GLSLProgram
{
public:
			GLSLProgram				();

	void	CompileShader			(const char * aFilename);
	void	CompileShader			(const char * aFilename, GLSLShader::GLSLShaderType aShaderType);
	void	CompileShader			(const std::string& aSource, GLSLShader::GLSLShaderType aShaderType, const char * aFilename = NULL);

	void	Link					();
	void	UseProgram				();
	void	Validate				();
	int		GetHandle				();
	bool	IsLinked				();
	
	void	BindAttribLocation		(GLuint aLocation, const char * aName);
	void	BindFragDataLocation	(GLuint aLocation, const char * aName);
	
	void	SetUniform				(const char *aName, float aX, float aY, float aZ);
	void	SetUniform				(const char *aName, const glm::vec3 & aVec3);
	void	SetUniform				(const char *aName, const glm::vec4 & aVec4);
	void	SetUniform				(const char *aName, const glm::mat3 & aMat3);
	void	SetUniform				(const char *aName, const glm::mat4 & aMat4);
	void	SetUniform				(const char *aName, float aVal);
	void	SetUniform				(const char *aName, int   aVal);
	void	SetUniform				(const char *aName, bool  aVal);
	
	void	PrintActiveUniforms		();
	void	PrintActiveAttribs		();
	void	PrintActiveUniformBlocks();

private:

	int							mHandle;
	bool						mLinked;
	std::map<std::string, int>	mUniformLocations;

	int GetUniformLocation(const char * aName);
};

#endif //__SKETCHY_GLSLPROGRAM__