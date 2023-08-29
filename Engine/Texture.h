#pragma once
#include "Object.h"

class Texture : public Object
{
public:
	Texture();
	virtual ~Texture();
	void Init(const wstring& path);

	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle() { return _srvHandle; }

public:
	void CreateTexture(const wstring& path);
	void CreateView();

private:
	ScratchImage			 		_image;  // texture 로드하는 부분
	ComPtr<ID3D12Resource>			_tex2D;

	ComPtr<ID3D12DescriptorHeap>	_srvHeap; // view 만드는 부분
	D3D12_CPU_DESCRIPTOR_HANDLE		_srvHandle = {};
};
