#include "blockerpch.h"
#include "Layer.h"
namespace Blocker
{
	Layer::Layer(const std::string& debugName) : m_DebugName(debugName)
	{
	}

	Layer::~Layer()
	{
	}
	void Layer::OnAttach()
	{
	}
	void Layer::OnDetach()
	{
	}
	void Layer::OnUpdate()
	{
	}
	void Layer::OnEvent(Event& event)
	{
	}
}
