#pragma once

#include "Renderer/VertexArray.h"

namespace HazelPVR
{
    class OpenGLVertexArray : public VertexArray
    {
        public:
            OpenGLVertexArray();
            virtual ~OpenGLVertexArray();
        
        public:
            virtual void Bind() const override;
            virtual void Unbind() const override;

            virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VertexBuffer) override;
            virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& IndexBuffer) override;

            virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return m_VertexBuffers; }
            virtual const std::shared_ptr<IndexBuffer>& GetIndexexBuffer() const override { return m_IndexBuffer; }

        private:
            uint32_t m_RendererID;
            std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
            std::shared_ptr<IndexBuffer> m_IndexBuffer;
   };
}