#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void GreenSeperation(Image& img) {

	int width = img.getSize().x;
	int height = img.getSize().y;

	for (int y = 0; y < height - 1; y++) {
		for (int x = 0; x < width - 1; x++) {
			Color pixColor = img.getPixel(x, y);
			pixColor.r = 0;
			pixColor.b = 0;
			img.setPixel(x, y, pixColor);
		}
	}



}

int main()
{
	Image img;
	img.loadFromFile("../images/winter.png");
	GreenSeperation(img);
	img.saveToFile("green.png");

	//show image
	Texture tex1;
	tex1.loadFromImage(img);
	RenderWindow window(sf::VideoMode(800, 600), "Show me a picture");
	Sprite sprite1;
	sprite1.setTexture(tex1);
	window.draw(sprite1);
	window.display();

	while (true);
}
