#pragma once

#include "Renderer/Buffer.h"

namespace HazelPVR
{
    class VertexArray
    {
        public:
            virtual ~VertexArray() {}

            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VertexBuffer) = 0;
            virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& IndexBuffer) = 0;

            virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
            virtual const std::shared_ptr<IndexBuffer>& GetIndexexBuffer() const = 0;

            static VertexArray* Create();
    };
}
