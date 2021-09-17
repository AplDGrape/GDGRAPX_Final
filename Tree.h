#pragma once
#include "main.h"

ObjData TreeData;

void InitializeTree() {
	LoadObjFile(&TreeData, "Tree/Tree.obj");

	GLfloat StatueOffsets[] = { 0.0f, 0.05f, -1.0f };

	LoadObjToMemory(
		&TreeData,
		1.0f,
		StatueOffsets
	);
}

void BindTreeArray() {
	glBindVertexArray(TreeData.vaoId);
}

void DrawTree() {
	glActiveTexture(GL_TEXTURE0);
	GLuint backPackTexture = TreeData.textures[TreeData.materials[0].diffuse_texname];
	glBindTexture(GL_TEXTURE_2D, backPackTexture);

	glActiveTexture(GL_TEXTURE1);
	GLuint normalTexture = TreeData.textures[TreeData.materials[0].bump_texname];
	glBindTexture(GL_TEXTURE_2D, normalTexture);

	glActiveTexture(GL_TEXTURE3);
	GLuint SecondTexture = TreeData.textures[TreeData.materials[1].diffuse_texname];
	glBindTexture(GL_TEXTURE_2D, SecondTexture);

	glActiveTexture(GL_TEXTURE4);
	GLuint SecondnormalTexture = TreeData.textures[TreeData.materials[1].bump_texname];
	glBindTexture(GL_TEXTURE_2D, SecondnormalTexture);

	//glEnable(GL_BLEND);
	glDrawElements(GL_TRIANGLES, TreeData.numFaces, GL_UNSIGNED_INT, (void*)0);
	//glDisable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D, 0);
}