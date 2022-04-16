#include "ScreenShot.h"


ScreenShot::ScreenShot() {}
ScreenShot::~ScreenShot() {}

void ScreenShot::SaveScreenShot(sf::RenderWindow& l_window) {
	sf::Texture texture;
	texture.create(l_window.getSize().x, l_window.getSize().y);
	texture.update(l_window);

	// put window texture into an image
	// copy from image 1 to image 2

	sf::Image image1 = texture.copyToImage();
	sf::Image image2;
	image2.create(441, 495);
	image2.copy(image1, 0, 0, sf::IntRect(325, 50, 441, 495));
	
	std::string timestamp = time_stamp("MASHA_%Y%m%d%H%M%S") + ".jpg";

	if (image2.saveToFile(timestamp))
	{
		std::cout << "screenshot saved to " << timestamp << std::endl;
	}
}
