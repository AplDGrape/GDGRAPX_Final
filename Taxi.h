#pragma once
#include "main.h"

ObjData TaxiData;

void InitializeTaxi() {
	LoadObjFile(&TaxiData, "Taxi/Taxi.obj");

	GLfloat StatueOffsets[] = { 0.0f, 0.05f, 3.0f };

	LoadObjToMemory(
		&TaxiData,
		1.0f,
		StatueOffsets
	);
}

void BindTaxiArray() {
	glBindVertexArray(TaxiData.vaoId);
}

void DrawTaxi() {
	glActiveTexture(GL_TEXTURE0);
	GLuint backPackTexture = TaxiData.textures[TaxiData.materials[0].diffuse_texname];
	glBindTexture(GL_TEXTURE_2D, backPackTexture);

	glActiveTexture(GL_TEXTURE1);
	GLuint normalTexture = TaxiData.textures[TaxiData.materials[0].bump_texname];
	glBindTexture(GL_TEXTURE_2D, normalTexture);

	glActiveTexture(GL_TEXTURE3);
	GLuint SecondTexture = TaxiData.textures[TaxiData.materials[1].diffuse_texname];
	glBindTexture(GL_TEXTURE_2D, SecondTexture);

	glActiveTexture(GL_TEXTURE4);
	GLuint SecondnormalTexture = TaxiData.textures[TaxiData.materials[1].bump_texname];
	glBindTexture(GL_TEXTURE_2D, SecondnormalTexture);

	//glEnable(GL_BLEND);
	glDrawElements(GL_TRIANGLES, TaxiData.numFaces, GL_UNSIGNED_INT, (void*)0);
	//glDisable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D, 0);
}