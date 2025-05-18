#include "raylib.h"
#include "Prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex):
    worldPos(pos),
    Texture(tex)
{

}

void Prop::Render(Vector2 knightPos)
{
    Vector2 screenPos{Vector2Subtract(worldPos, knightPos)};
    DrawTextureEx(Texture, screenPos, 0.f, scale, WHITE);
}

Rectangle Prop::GetCollisionRec(Vector2 knightPos)
{
    Vector2 screenPos{Vector2Subtract(worldPos, knightPos)};
    return Rectangle{
        screenPos.x,
        screenPos.y,
        Texture.width * scale,
        Texture.height * scale,
    };
}