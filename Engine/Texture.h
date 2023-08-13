#pragma once

class Texture
{
public:
	void Init(const wstring& path);

	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle() { return _srvHandle; }

public:
	void CreateTexture(const wstring& path);
	void CreateView();

private:
	ScratchImage			 		_image;  // texture �ε��ϴ� �κ�
	ComPtr<ID3D12Resource>			_tex2D;

	ComPtr<ID3D12DescriptorHeap>	_srvHeap; // view ����� �κ�
	D3D12_CPU_DESCRIPTOR_HANDLE		_srvHandle;
};
