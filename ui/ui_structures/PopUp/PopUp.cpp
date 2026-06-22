#include "PopUp.hpp"

PopUp::PopUp(
        const std::string &title, 
        const std::string &description, 
        const std::string &buttonText, 
        sf::Color titleColor, 
        sf::Color descriptionColor, 
        sf::Color buttonColorText, 
        const sf::Font &fontBold, 
        const sf::Font &fontLight, 
        unsigned int textPunto, 
        sf::Vector2f size, 
        sf::Color popUpBgColor, 
        sf::Color popUpOutlineColor, 
        float popUpOutlineThickness, 
        sf::Color errorBgShadeColor, 
        sf::Color buttonBgColor,
        sf::RenderWindow &window
    ) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    this->bgShade.setSize(sf::Vector2f(windowWidth, windowHeight));
    this->bgShade.setPosition(0.0f, 0.0f);
    this->bgShade.setFillColor(errorBgShadeColor);

    this->errorPopUp.setSize(size);
    this->errorPopUp.setFillColor(popUpBgColor);
    this->errorPopUp.setOutlineColor(popUpOutlineColor);
    this->errorPopUp.setOutlineThickness(popUpOutlineThickness);
    positionPopUpWindow(windowWidth, windowHeight);

    this->title.setFont(fontBold);
    this->title.setFillColor(titleColor);
    this->title.setString(title);
    this->title.setTextPunto(textPunto);
    centerTitle();

    this->description.setFont(fontLight);
    this->description.setFillColor(descriptionColor);
    this->description.setString(description);
    this->description.setTextPunto(textPunto);
    centerDescription();

    this->dismissButton = Button(sf::Vector2f(size.x * 0.4f, size.y * 0.2f), sf::Vector2f(0.0f, 0.0f), buttonBgColor, popUpOutlineColor, popUpOutlineThickness, buttonText, fontBold, textPunto, buttonColorText);
    centerButton();
}

void PopUp::positionPopUpWindow(float windowWidth, float windowHeight) {

    sf::FloatRect popupBounds = this->errorPopUp.getLocalBounds();

    this->errorPopUp.setOrigin(popupBounds.left + popupBounds.width / 2.0f, popupBounds.top + popupBounds.height / 2.0f);
    this->errorPopUp.setPosition(windowWidth / 2.0f, windowHeight / 2.0f);
}

void PopUp::setSizePopUpWindow(float windowWidth, float windowHeight) {

    this->errorPopUp.setSize(sf::Vector2f(windowWidth * 0.5, windowHeight * 0.5));
}

void PopUp::centerTitle() {

    sf::FloatRect titleBounds = this->title.getLocalBounds();
    sf::FloatRect popUpBounds = this->errorPopUp.getGlobalBounds();

    this->title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    this->title.setPosition(popUpBounds.left + popUpBounds.width / 2.0f, popUpBounds.top + popUpBounds.height * 0.25f);
}

void PopUp::centerDescription() {

    sf::FloatRect descriptionBounds = this->description.getLocalBounds();
    sf::FloatRect popUpBounds = this->errorPopUp.getGlobalBounds();

    this->description.setOrigin(descriptionBounds.left + descriptionBounds.width / 2.0f, descriptionBounds.top + descriptionBounds.height / 2.0f);
    this->description.setPosition(popUpBounds.left + popUpBounds.width / 2.0f, popUpBounds.top + popUpBounds.height * 0.48f);
}

void PopUp::centerButton() {

    this->dismissButton.setOriginCenter();
    
    sf::FloatRect popUpBounds = this->errorPopUp.getGlobalBounds();
    this->dismissButton.setPosition(sf::Vector2f(popUpBounds.left + popUpBounds.width / 2.0f, popUpBounds.top + popUpBounds.height * 0.80f));
}

void PopUp::adjustScaling() {

}

bool PopUp::isDismissed(sf::Vector2f &mousePosition) {

    return this->dismissButton.isClicked(mousePosition);
}

bool PopUp::dismissHoverState(sf::Vector2f &mousePosition, sf::Color dismissBackgroundColor, sf::Color dismissTextColor) {

    return this->dismissButton.hoverState(mousePosition, dismissBackgroundColor, dismissTextColor);
}

void PopUp::drawPopUp(sf::RenderWindow &window) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    this->bgShade.setSize(sf::Vector2f(windowWidth, windowHeight));
    positionPopUpWindow(windowWidth, windowHeight);
    setSizePopUpWindow(windowWidth, windowHeight);
    centerTitle();
    centerDescription();
    centerButton();

    window.draw(this->bgShade);
    window.draw(this->errorPopUp);
    window.draw(this->title);
    window.draw(this->description);
    this->dismissButton.drawButton(window);
}