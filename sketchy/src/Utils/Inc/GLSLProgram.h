/*
@class	CShader
*/

#ifndef __SKETCHY_GLSLPROGRAM__
#define __SKETCHY_GLSLPROGRAM__

#include<string>
#include<map>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

namespace GLSLShader
{
	enum EGLSLShaderType
	{
		eST_Invalid			= -1,
		eST_Vertex			= GL_VERTEX_SHADER,
		eST_Fragment		= GL_FRAGMENT_SHADER,
		eST_Geometry		= GL_GEOMETRY_SHADER,
		/* @todo: investigate where are defined
		eST_TessControl		= GL_TESS_CONTROL_SHADER,
		eST_TessEvaluation	= GL_TESS_EVALUATION_SHADER,
		eST_Compute			= GL_COMPUTE_SHADER*/
		eST_Count
	};
};

class GLSLProgram
{
public:
			GLSLProgram				();

	void	CompileShader			(const char * aFilename);
	void	CompileShader			(const char * aFilename, GLSLShader::EGLSLShaderType aShaderType);
	bool	CompileShader			(const char * aSource  , GLSLShader::EGLSLShaderType aShaderType, const char * aFilename = NULL);

	bool	Link					();

	void	UseProgram				() const;
	void	Validate				() const;

	GLuint	GetHandle				() const { return mProgramHandle;   }
	bool	IsLinked				() const { return mIsLinked;		}
	
	void	BindAttribLocation		(GLuint aLocation, const char * aName) const;
	void	BindFragDataLocation	(GLuint aLocation, const char * aName) const;
	
	void	SetUniform				(const char *aName, float aX, float aY, float aZ);
	void	SetUniform				(const char *aName, const glm::vec3 & aVec3);
	void	SetUniform				(const char *aName, const glm::vec4 & aVec4);
	void	SetUniform				(const char *aName, const glm::mat3 & aMat3);
	void	SetUniform				(const char *aName, const glm::mat4 & aMat4);
	void	SetUniform				(const char *aName, float aVal);
	void	SetUniform				(const char *aName, int   aVal);
	void	SetUniform				(const char *aName, bool  aVal);
	
	void	PrintActiveUniforms		() const;
	void	PrintActiveAttribs		() const;
	void	PrintActiveUniformBlocks() const;

private:

	GLuint  					mProgramHandle;
	GLuint 						mShaderHandles[GLSLShader::eST_Count];
	bool						mIsLinked;
	std::map<std::string, int>	mUniformLocations;

	int			GetUniformLocation	(const char * aName) const;
	const char* GetShaderTypeString (GLSLShader::EGLSLShaderType aShaderType);
};


#endif //__SKETCHY_GLSLPROGRAM__
