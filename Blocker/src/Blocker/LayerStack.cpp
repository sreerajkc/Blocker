#include "blockerpch.h"
#include "LayerStack.h"

namespace Blocker
{
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer); // insert elements at the given position
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay); // insert an element at the end of the vector
	}

	void LayerStack::PopLayers(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer); // find the first occurrence of an element in the given range
		if (it != m_Layers.end()) // end is a theoratical element comes after last element
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}