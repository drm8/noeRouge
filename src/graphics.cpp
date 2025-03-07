#include "raylib.h"
#include "list"

const float defaultCamWidth = 320;
const float defaultCamHeight = 180;

class TextureHandler
{
	private:

	public:
	TextureHandler( )
	{

	}
};

class ScreenHandler
{
	private:
	int width = 1280;
	int height = 720;
	public:
	ScreenHandler( )
	{
		InitWindow( width, height, "test" );
		SetTargetFPS( 60 );
	}
	void onTick( )
	{
		BeginDrawing( );
		ClearBackground( RAYWHITE );
		DrawText( "Hello World!", 500, 300, 60, BLACK );
		EndDrawing( );
	}

};

class Camera
{
	private:
	std::list<Sprite> buffer;
	Vector2 position;
	Vector2 size;
	float renderScale;
	Rectangle viewRectangle;
	public:
	Camera( Vector2 position, Vector2 size, float renderScale )
	{
		buffer = { };
		this->position = position;
		this->size = size;
		this->renderScale = renderScale;
		viewRectangle = { position.x - size.x / 2, position.y - size.y / 2, size.x, size.y };
	}
	Camera( Vector2 size, float renderScale ) : Camera( Vector2 { 0, 0 }, size, renderScale ) { }
	Camera( ) : Camera( Vector2 { defaultCamWidth, defaultCamHeight }, 1.0f ) { }
	
	Rectangle moveTo( Vector2 position )
	{
		this->position = position;
		viewRectangle = { position.x - size.x / 2, position.y - size.y / 2, size.x, size.y };
		return viewRectangle;
	}

	void render( )
	{
		// TODO: Implement view culling

		// TODO: Implement layer sorting

		for ( Sprite sprite : buffer )
		{
			sprite.render( this );
		}

		buffer.clear( );
	}
};

class Sprite
{
	private:
	Texture2D texture;
	Rectangle sourceRect;
	Vector2 sourcePosition;
	Vector2 realPosition;
	int scale = 1;
	float rotation = 0;
	Vector2 pivotPoint;
	Rectangle boundingRect;
	public:
	Sprite( Texture2D texture, Vector2 position )
	{
		this->texture = texture;
		sourcePosition = position;
		realPosition = position;
		realPosition.x -= texture.width / 2;
		realPosition.y -= texture.height / 2;
	}
	Sprite( Texture2D texture, Vector2 position, double rotation )
	{
		Sprite( texture, position );
		this->texture = texture;
		this->rotation = rotation;
		sourcePosition = position;
		realPosition = position;
		realPosition.x -= texture.width / 2;
		realPosition.y -= texture.height / 2;
	}

	void setPosition( Vector2 position )
	{

	}

	void render( Camera *camera )
	{
		// float x = camera->position.x;
	}
};

