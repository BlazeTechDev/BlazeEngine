#include <Blaze.hpp>

class EditorLayer : public Blaze::Layer
{
public:
	EditorLayer() : Layer("Editor") {};

	void OnUpdate() override
	{
		BLZ_CLIENT_INFO("EditorLayer:Update");
	}
	
	void OnEvent(Blaze::Event& event) override
	{
		BLZ_CLIENT_TRACE("{0}", event);
	}
};

class Editor : public Blaze::Application
{
public:
	Editor()
	{
		PushLayer(new EditorLayer());
		PushOverlay(new Blaze::ImGuiLayer());
	}

	~Editor()
	{

	}
};

Blaze::Application* Blaze::CreateApplication()
{
	return new Editor();
}