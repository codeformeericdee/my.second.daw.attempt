//Written by Eric Dee.

#include "AUM-Ono-API-Graphics-Vertex-Buffer.h"

namespace AUM_Ono_API_Graphics {

	AUMOnoAPIGraphicsVertexBuffer::AUMOnoAPIGraphicsVertexBuffer
		()
	{
		this->phaseBufferId = 0;
	}

	AUMOnoAPIGraphicsVertexBuffer::AUMOnoAPIGraphicsVertexBuffer
		(unsigned int size, const void* plotPoints)
	{
		glGenBuffers(1, &this->phaseBufferId);
		glBindBuffer(GL_ARRAY_BUFFER, this->phaseBufferId);
		glBufferData(GL_ARRAY_BUFFER, size, plotPoints, GL_STATIC_DRAW);
	}

	AUMOnoAPIGraphicsVertexBuffer::~AUMOnoAPIGraphicsVertexBuffer
		(){}

	void AUMOnoAPIGraphicsVertexBuffer::Bind
		()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->phaseBufferId);
	}

	void AUMOnoAPIGraphicsVertexBuffer::Unbind
		() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	unsigned int* AUMOnoAPIGraphicsVertexBuffer::GetAddress
	()
	{
		return &this->phaseBufferId;
	}

}