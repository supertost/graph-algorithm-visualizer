#include "PopUp.hpp"

PopUp::PopUp(
                const std::string &titleText, 
                const std::string &descriptionText, 
                const std::string &buttonText,
                const sf::Font &font, 
                sf::Vector2f size,
                const PopUpStyle &style,
                sf::RenderWindow &window
        )
{
        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        
        bgShade.setSize(sf::Vector2f(windowWidth, windowHeight));
        bgShade.setPosition(0.0f, 0.0f);
        
        errorPopUp.setSize(size);
        positionPopUpWindow(windowWidth, windowHeight);
        
        title.setString(titleText);
        centerTitle();
        
        description.setString(descriptionText);
        centerDescription();
        
        setStyle(style);
        dismissButton = Button(
                                buttonText, 
                                sf::Vector2f(0.0f, 0.0f), 
                                sf::Vector2f(0.0f, 0.0f), 
                                font,
                                style.defaultStyle,
                                style.hoverStyle
                        );
        centerButton();
}

void PopUp::setFont(const sf::Font &font)
{
        title.setFont(font);
        description.setFont(font);
}

void PopUp::setStyle(const PopUpStyle &newStyle)
{
        style = newStyle;

        bgShade.setFillColor(style.bgShadeColor);

        errorPopUp.setFillColor(style.backgroundColor);
        errorPopUp.setOutlineColor(style.outlineColor);
        errorPopUp.setOutlineThickness(style.outlineThickness);

        title.setFillColor(style.titleColor);
        title.setCharacterSize(style.titlePunto);

        description.setFillColor(style.descriptionColor);
        description.setCharacterSize(style.descriptionPunto);
}

void PopUp::positionPopUpWindow(float windowWidth, float windowHeight)
{
        sf::FloatRect popupBounds = errorPopUp.getLocalBounds();

        errorPopUp.setOrigin(
                popupBounds.left + popupBounds.width / 2.0f,
                popupBounds.top + popupBounds.height / 2.0f
        );

        errorPopUp.setPosition(windowWidth / 2.0f, windowHeight / 2.0f);
}

void PopUp::setSizePopUpWindow(float windowWidth, float windowHeight)
{
    errorPopUp.setSize(sf::Vector2f(windowWidth * 0.5, windowHeight * 0.5));
}

void PopUp::centerTitle()
{
        sf::FloatRect titleBounds = title.getLocalBounds();
        sf::FloatRect popUpBounds = errorPopUp.getGlobalBounds();

        title.setOrigin(
                titleBounds.left + titleBounds.width / 2.0f,
                titleBounds.top + titleBounds.height / 2.0f
        );
    
        title.setPosition(
                popUpBounds.left + popUpBounds.width / 2.0f,
                popUpBounds.top + popUpBounds.height * 0.25f
        );
}

void PopUp::centerDescription()
{
        sf::FloatRect descriptionBounds = description.getLocalBounds();
        sf::FloatRect popUpBounds = errorPopUp.getGlobalBounds();

        description.setOrigin(
                descriptionBounds.left + descriptionBounds.width / 2.0f,
                descriptionBounds.top + descriptionBounds.height / 2.0f
        );
        
        description.setPosition(
                popUpBounds.left + popUpBounds.width / 2.0f,
                popUpBounds.top + popUpBounds.height * 0.48f
        );
}

void PopUp::centerButton()
{
        dismissButton.setOriginCenter();
        sf::FloatRect popUpBounds = errorPopUp.getGlobalBounds();
        
        dismissButton.setPosition(
                sf::Vector2f(
                        popUpBounds.left + popUpBounds.width / 2.0f, 
                        popUpBounds.top + popUpBounds.height * 0.80f
                )
        );
}

void PopUp::adjustScaling()
{

}

bool PopUp::isDismissed(const sf::Vector2f &mousePosition)
{
    return dismissButton.isClicked(mousePosition);
}

bool PopUp::dismissHoverState(const sf::Vector2f &mousePosition)
{
    return dismissButton.hoverState(mousePosition);
}

void PopUp::drawPopUp(sf::RenderWindow &window)
{
    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    bgShade.setSize(sf::Vector2f(windowWidth, windowHeight));
    positionPopUpWindow(windowWidth, windowHeight);
    setSizePopUpWindow(windowWidth, windowHeight);
    centerTitle();
    centerDescription();
    centerButton();

    window.draw(bgShade);
    window.draw(errorPopUp);
    window.draw(title);
    window.draw(description);
    dismissButton.drawButton(window);
}