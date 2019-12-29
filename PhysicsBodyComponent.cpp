#include "stdafx.h"
#include "PhysicsBodyComponent.h"
#include "TransformComponent.h"
#include "Object.h"
void PhysicsBodyComponent::Init(BodyType type, float32 friction, float32 density, float32 restitution,BOOL isBullet, BOOL isSensor)
{
	_trans = _object->GetTrans();
	_type = type;
	switch (_type)
	{
		case DYNAMIC:
		{
			Vector2 bodyPosition = { _trans->GetPos().x, _trans->GetPos().y };
			bodyPosition = Convert(bodyPosition);

			b2BodyDef bodyDef;
			bodyDef.type = b2BodyType::b2_dynamicBody; //static은 무조건 고정,dynamic은 움직임
			if(isBullet) bodyDef.bullet;
			bodyDef.userData = _object;
			bodyDef.position.Set(bodyPosition.x, bodyPosition.y);
			_body = BOXWORLDMANAGER->GetWorld()->CreateBody(&bodyDef);  //bodyDef의 내용을 바탕으로 body를 만듬

			Vector2 bodySize = { _trans->GetScale().x / 2.f,_trans->GetScale().y / 2.f };
			bodySize = Convert(bodySize);

			b2PolygonShape shape;
			shape.SetAsBox(bodySize.x, bodySize.y);

			b2FixtureDef fixture;
			fixture.isSensor = isSensor;//충돌함수는 실행하지만 박스를 밀어낼것인가 안밀어내것인가?
			fixture.shape = &shape;
			fixture.density = density;
			fixture.friction = friction;
			fixture.restitution = restitution;
			_body->CreateFixture(&fixture);

			break;
		}

		case STATIC:
		{
			//Vector2 bodyPosition = { _trans->GetPos().x / 2.f, _trans->GetPos().y / 2.f };
			Vector2 bodyPosition = { _trans->GetPos().x , _trans->GetPos().y  };
			bodyPosition = Convert(bodyPosition);

			b2BodyDef bodyDef;
			bodyDef.userData = _object;
			bodyDef.position.Set(bodyPosition.x, bodyPosition.y);
			_body = BOXWORLDMANAGER->GetWorld()->CreateBody(&bodyDef);  //bodyDef의 내용을 바탕으로 body를 만듬

			Vector2 bodySize = { _trans->GetScale().x / 2.f,_trans->GetScale().y / 2.f };
			bodySize = Convert(bodySize);

			b2PolygonShape shape;
			shape.SetAsBox(bodySize.x, bodySize.y);

			b2FixtureDef fixture;
			fixture.isSensor = isSensor;//충돌함수는 실행하지만 박스를 밀어낼것인가 안밀어내것인가?
			fixture.shape = &shape;
			fixture.density = density;
			fixture.friction = friction;
			_body->CreateFixture(&fixture);

			break;
		}

		case KINEMATIC:
		{
			Vector2 bodyPosition = { _trans->GetPos().x , _trans->GetPos().y };
			bodyPosition = Convert(bodyPosition);

			b2BodyDef bodyDef;
			bodyDef.type = b2BodyType::b2_kinematicBody; //static은 무조건 고정,dynamic은 움직임
			bodyDef.userData = _object;
			bodyDef.position.Set(bodyPosition.x, bodyPosition.y);
			_body = BOXWORLDMANAGER->GetWorld()->CreateBody(&bodyDef);  //bodyDef의 내용을 바탕으로 body를 만듬

			Vector2 bodySize = { _trans->GetScale().x / 2.f,_trans->GetScale().y / 2.f };
			bodySize = Convert(bodySize);

			b2PolygonShape shape;
			shape.SetAsBox(bodySize.x, bodySize.y);

			b2FixtureDef fixture;
			fixture.isSensor = isSensor;//충돌함수는 실행하지만 박스를 밀어낼것인가 안밀어내것인가?
			fixture.shape = &shape;
			fixture.density = density;
			fixture.friction = friction;
			_body->CreateFixture(&fixture);

			break;
		}
	}

}



void PhysicsBodyComponent::SetBodyPosition()
{

	Vector2 bodyPosition = { _object->GetTrans()->GetPos().x, _object->GetTrans()->GetPos().y };
	bodyPosition = Convert(bodyPosition);

	_body->SetTransform(b2Vec2(bodyPosition.x, bodyPosition.y), _body->GetAngle());
}


Vector2 PhysicsBodyComponent::GetBodyPosition()
{
	return Vector2(_body->GetPosition().x * 100.f, _body->GetPosition().y * 100.f);
}

Vector2 PhysicsBodyComponent::GetBodyScale()
{
	return Vector2(_body->GetTransform().p.x*100.f, _body->GetTransform().p.y*100.f);
}

Vector2 PhysicsBodyComponent::Convert(Vector2 origin)
{
	return Vector2(origin.x*0.01f, origin.y*0.01f);
}
