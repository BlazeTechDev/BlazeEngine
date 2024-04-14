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

		m_ViewportCamera = std::shared_ptr<Blaze::Camera>(new Blaze::Camera());
		m_ViewportCamera->GetGraphicalData().position = glm::vec3(0, 0, 0);
		m_ViewportCamera->GetGraphicalData().rotation = glm::vec3(0, 0, 0);
		Blaze::Graphics::Get()->SetActiveCamera(m_ViewportCamera);
	}

	virtual void OnUpdate(Blaze::Timestep timeStep) override
	{

	}
	
	virtual void OnEvent(Blaze::Event& event) override
	{

	}

private:
	Blaze::ImGuiLayer* s_ImGuiLayer;

	std::shared_ptr<Blaze::Camera> m_ViewportCamera;
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