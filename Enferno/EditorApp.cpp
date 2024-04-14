#include <Blaze.hpp>

class EditorLayer : public Blaze::Layer
{
public:
	EditorLayer(Blaze::ImGuiLayer* imGuiLayer) : Layer("Editor"), s_ImGuiLayer(imGuiLayer) {};

	virtual void OnAttach() override
	{
		s_ImGuiLayer->PushEditorWindow(new Blaze::ConsoleWindow());
		s_ImGuiLayer->PushEditorWindow(new Blaze::SceneViewport());
		s_ImGuiLayer->PushEditorWindow(new Blaze::PropertiesWindow());
		s_ImGuiLayer->PushEditorWindow(new Blaze::CollectionWindow());

		Blaze::Graphics::Get()->SetActiveCamera(new Blaze::Camera());
	}

	virtual void OnUpdate(Blaze::Timestep timeStep) override
	{

	}
	
	virtual void OnEvent(Blaze::Event& event) override
	{

	}

private:
	Blaze::ImGuiLayer* s_ImGuiLayer;
};

class Editor : public Blaze::Application
{
public:
	Editor()
	{
		Blaze::ImGuiLayer* imGuiLayer = new Blaze::ImGuiLayer();
		PushLayer(new EditorLayer(imGuiLayer));
		PushOverlay(imGuiLayer);
	}

	~Editor()
	{

	}
};

Blaze::Application* Blaze::CreateApplication()
{
	return new Editor();
}