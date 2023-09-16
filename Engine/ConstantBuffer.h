#pragma once

enum class CONSTANT_BUFFER_TYPE : uint8
{
	GLOBAL, // global data - ex. lighting
	TRANSFORM,
	MATERIAL,
	END  // for counting
};

enum
{
	CONSTANT_BUFFER_COUNT = static_cast<uint8>(CONSTANT_BUFFER_TYPE::END)
};

class ConstantBuffer
{
public:
	ConstantBuffer();
	~ConstantBuffer();

	// 어떤 레지스터에 넣어줘야 할지도 받아옴
	void Init(CBV_REGISTER reg, uint32 size, uint32 count);

	void Clear();
	void PushData(void* buffer, uint32 size);

	// gloabal data 위한 함수
	// 세팅 한번만 해두고 사용할 것이므로 매번 clear, push 하지 않음
	void SetGlobalData(void* buffer, uint32 data);


	D3D12_GPU_VIRTUAL_ADDRESS GetGpuVirtualAddress(uint32 index);
	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle(uint32 index);

private:
	void CreateBuffer();
	void CreateView();

private:
	ComPtr<ID3D12Resource>	_cbvBuffer;
	BYTE*					_mappedBuffer = nullptr;
	uint32					_elementSize = 0;
	uint32					_elementCount = 0;

	ComPtr<ID3D12DescriptorHeap>	_cbvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE		_cpuHandleBegin = {};
	uint32							_handleIncrementSize = 0;

	uint32					_currentIndex = 0;
	
	CBV_REGISTER			_reg = {};
};
