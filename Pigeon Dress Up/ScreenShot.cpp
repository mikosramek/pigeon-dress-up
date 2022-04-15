#include "ScreenShot.h"


ScreenShot::ScreenShot() {}
ScreenShot::~ScreenShot() {}

void ScreenShot::SaveScreenShot(sf::RenderWindow& l_window) {
	sf::Texture texture;
	texture.create(l_window.getSize().x, l_window.getSize().y);
	//texture.loadFromImage(l_window.capture(), sf::IntRect(325, 50, 442, 495));
	texture.update(l_window);

	time_t t = time(0);
	std::tm bt{};
	localtime_s(&bt, &t);
	std::string timestamp = time_stamp("MASHA_%Y%m%d%H%M%S") + ".jpg";

	if (texture.copyToImage().saveToFile(timestamp))
	{
		std::cout << "screenshot saved to " << timestamp << std::endl;
	}
}
