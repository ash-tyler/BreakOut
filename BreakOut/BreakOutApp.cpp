#include "BreakOutApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <glm\ext.hpp>
#include <Gizmos.h>

BreakOutApp::BreakOutApp() 
{

}

BreakOutApp::~BreakOutApp() 
{

}

bool BreakOutApp::startup() 
{
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);		//TODO: remember to change this when redistributing a build! The following path would be used instead: "./font/consolas.ttf"

	m_physicsScene = new PhysicsScene();
	m_physicsScene->setTimeStep(0.01f);

	return true;
}

void BreakOutApp::shutdown() 
{
	delete m_font;
	delete m_2dRenderer;
}

void BreakOutApp::update(float deltaTime) 
{
	aie::Input* input = aie::Input::getInstance();


	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime);
	m_physicsScene->draw();


	/*static const glm::vec4 colours[] =
	{
		glm::vec4(1, 0, 0, 1), glm::vec4(0, 1, 0, 1),
		glm::vec4(0, 0, 1, 1), glm::vec4(0.8f, 0, 0.5f, 1),
		glm::vec4(0, 1, 1, 1)
	};


	static const int rows = 5;
	static const int columns = 10;
	static const int hSpace = 1;
	static const int vSpace = 1;

	static const glm::vec2 scrExtents(100, 50);
	static const glm::vec2 boxExtents(7, 3);
	static const glm::vec2 startPos(-(columns >> 1)*((boxExtents.x * 2) + vSpace) + boxExtents.x + (vSpace / 2.0f), scrExtents.y - ((boxExtents.y * 2) + hSpace));


	glm::vec2 pos;
	for (int y = 0; y < rows; y++)
	{
		pos = glm::vec2(startPos.x, startPos.y - (y* ((boxExtents.y * 2) + hSpace)));
		for (int x = 0; x < columns; x++)
		{
			aie::Gizmos::add2DAABBFilled(pos, boxExtents, colours[y]);
			pos.x += (boxExtents.x * 2) + vSpace;
		}
	}


	aie::Gizmos::add2DCircle(glm::vec2(0, -35), 3, 12, glm::vec4(1, 1, 0, 1));
	aie::Gizmos::add2DAABBFilled(glm::vec2(0, -40), glm::vec2(12, 2), glm::vec4(1, 0, 1, 1));*/


	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void BreakOutApp::draw() 
{
	clearScreen();
	m_2dRenderer->begin();


	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));

	
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->end();
}