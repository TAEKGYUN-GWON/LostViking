#include "stdafx.h"
#include "PhysicsBodyComponent.h"
#include "TransformComponent.h"


PhysicsBodyComponent::PhysicsBodyComponent(Object* object)
{
	_object = object;
}


PhysicsBodyComponent::~PhysicsBodyComponent()
{
}

void PhysicsBodyComponent::AddDynamicBody(b2World *world)
{

	Vector2 bodyPosition = { _object->GetTrans()->GetPos().GetX() / 2.f, _object->GetTrans()->GetPos().GetY()/ 2.f };
	bodyPosition = Convert(bodyPosition);

	b2BodyDef bodyDef;
	bodyDef.type = b2BodyType::b2_dynamicBody; //static은 무조건 고정,dynamic은 움직임
	bodyDef.userData = _object;
	bodyDef.position.Set(bodyPosition.GetX(), bodyPosition.GetY());
	_body = world->CreateBody(&bodyDef);  //bodyDef의 내용을 바탕으로 body를 만듬

	Vector2 bodySize = { _object->GetTrans()->GetScale().GetX() / 2.f,_object->GetTrans()->GetScale().GetY() / 2.f };
	bodySize = Convert(bodySize);

	b2PolygonShape shape;
	shape.SetAsBox(bodySize.GetX(), bodySize.GetY());

	b2FixtureDef fixture;
	fixture.isSensor = false;//충돌함수는 실행하지만 박스를 밀어낼것인가 안밀어내것인가?
	fixture.shape = &shape;
	_body->CreateFixture(&fixture);

}

void PhysicsBodyComponent::AddStaticBody(b2World * world)
{

	Vector2 bodyPosition = { _object->GetTrans()->GetPos().GetX() / 2.f, _object->GetTrans()->GetPos().GetY() / 2.f };
	bodyPosition = Convert(bodyPosition);

	b2BodyDef bodyDef;
	bodyDef.userData = _object;
	bodyDef.position.Set(bodyPosition.GetX(), bodyPosition.GetY());
	_body = world->CreateBody(&bodyDef);  //bodyDef의 내용을 바탕으로 body를 만듬

	Vector2 bodySize = { _object->GetTrans()->GetScale().GetX() / 2.f,_object->GetTrans()->GetScale().GetY() / 2.f };
	bodySize = Convert(bodySize);

	b2PolygonShape shape;
	shape.SetAsBox(bodySize.GetX(), bodySize.GetY());

	b2FixtureDef fixture;
	fixture.isSensor = false;//충돌함수는 실행하지만 박스를 밀어낼것인가 안밀어내것인가?
	fixture.shape = &shape;
	_body->CreateFixture(&fixture);

}

void PhysicsBodyComponent::AddkinematicBody(b2World * world)
{

	Vector2 bodyPosition = { _object->GetTrans()->GetPos().GetX() / 2.f, _object->GetTrans()->GetPos().GetY() / 2.f };
	bodyPosition = Convert(bodyPosition);

	b2BodyDef bodyDef;
	bodyDef.type = b2BodyType::b2_kinematicBody; //static은 무조건 고정,dynamic은 움직임
	bodyDef.userData = _object;
	bodyDef.position.Set(bodyPosition.GetX(), bodyPosition.GetY());
	_body = world->CreateBody(&bodyDef);  //bodyDef의 내용을 바탕으로 body를 만듬

	Vector2 bodySize = { _object->GetTrans()->GetScale().GetX() / 2.f,_object->GetTrans()->GetScale().GetY() / 2.f };
	bodySize = Convert(bodySize);

	b2PolygonShape shape;
	shape.SetAsBox(bodySize.GetX(), bodySize.GetY());

	b2FixtureDef fixture;
	fixture.isSensor = false;//충돌함수는 실행하지만 박스를 밀어낼것인가 안밀어내것인가?
	fixture.shape = &shape;
	_body->CreateFixture(&fixture);

}


void PhysicsBodyComponent::SetBodyPosition()
{

	Vector2 bodyPosition = { _object->GetTrans()->GetPos().GetX(), _object->GetTrans()->GetPos().GetY() };
	bodyPosition = Convert(bodyPosition);

	_body->SetTransform(b2Vec2(bodyPosition.GetX(), bodyPosition.GetY()), _body->GetAngle());
}


Vector2 PhysicsBodyComponent::GetBodyPosition()
{
	return Vector2(_body->GetPosition().x * 100, _body->GetPosition().y * 100);
}

Vector2 PhysicsBodyComponent::Convert(Vector2 origin)
{
	return Vector2(origin.GetX()*0.01f, origin.GetY()*0.01f);
}
