#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main() {
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	RenderWindow window(VideoMode(1024, 768), "Here's the output");

	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();

	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();

	Color greenscreen;
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			if (y == 0 && x == 0) {
				greenscreen = foregroundImage.getPixel(x, y);
			}
			Color currPixelBackground = backgroundImage.getPixel(x, y);
			Color currPixelForeground = foregroundImage.getPixel(x, y);
			if (currPixelForeground == greenscreen) {
				foregroundImage.setPixel(x, y, currPixelBackground);
			}

		}
	}
	// By default, just show the foreground image

	Sprite sprite1;
	Texture tex1;
	//tex1.loadFromImage(backgroundImage);
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}
