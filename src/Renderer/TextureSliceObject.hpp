#pragma once


#include "Object3D.hpp"
#include "Texture3D.hpp"
#include "Texture1D.hpp"


class TextureSliceObject: public Object3D
{
	protected:
		struct Vertex
		{
			float x;
			float y;
			float z;
			float w;
		};
		
		struct Triangle
		{
			uint32_t v0;
			uint32_t v1;
			uint32_t v2;
		};
		
		static std::string vertSrc;
		static std::string fragSrc; 
		static int programShaderObject;
		static int vertexShaderObject;
		static int fragmentShaderObject;
		
		
		Texture1D* lutTexture; 
		
		Texture3D* volumeTexture; 
		Texture3D* gradientTexture; 
		
		unsigned int volumeSlices;
		
		unsigned int vertexBuffer;
		unsigned int elementBuffer;
		unsigned int vertexArrayObject;
		
		float brightness;
		float contrast;
		float threshold;
	
	public:
		static void InitSystem();
		
		TextureSliceObject();
		virtual void Init();
		virtual void Render(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);
		virtual void Destroy();
		
		void SetVolumeTexture(Texture3D* vt);
		void SetGradientTexture(Texture3D* gt);
		void SetLUTTexture(Texture1D* lt);
		void SetBrightness(double b);
		void SetContrast(double c);
		void SetThreshold(double t);
};