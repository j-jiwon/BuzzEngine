#pragma once
#include "Component.h"
#include "Frustrum.h"

enum class PROJECTION_TYPE
{
	PERSPECTIVE,
	ORTHOGRAPHIC,
};

class Camera : public Component
{
public:
	Camera();
	virtual ~Camera();

	virtual void FinalUpdate() override;
	void Render();

private:
	PROJECTION_TYPE _type = PROJECTION_TYPE::PERSPECTIVE;
	float _near = 1.f;
	float _far = 1000.f;
	float _fov = XM_PI / 4.f;
	float _scale = 1.f;

	// camera 마다 자기의 VP 가지고 있음. 카메라 여러개여도 각자 자기 것. 
	Matrix _matView = {}; 
	Matrix _matProjection = {};

	Frustrum _frustrum;

public:
	// TEMP: transform에 넘겨줄 데이터. static.
	static Matrix S_MatView;
	static Matrix S_MatProjection;
};

