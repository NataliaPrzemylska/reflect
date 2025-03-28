#pragma once
#include "renderer_p\shader\vulkan_shader.h"
#include "renderer_p\frame\frame_data.h"
namespace rfct {
	class vulkanRasterizerPipeline
	{
	public:
		vulkanRasterizerPipeline();
		~vulkanRasterizerPipeline();
		void createPipeline();
		void createRenderPass();
		void recordCommandBuffer(frameData& frameData, vk::Framebuffer framebuffer, uint32_t imageIndex);
		vk::RenderPass getRenderPass() { return m_renderPass.get(); }
	private:
		vulkanShader m_vertexShader;
		vulkanShader m_fragShader;
		vk::UniquePipelineLayout m_pipelineLayout;
		vk::UniquePipeline m_graphicsPipeline;
		vk::UniqueRenderPass m_renderPass;
	};
}