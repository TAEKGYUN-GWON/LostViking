#include "stdafx.h"
#include "PhysicsBodyComponent.h"
#include "TransformComponent.h"
#include "Object.h"
void PhysicsBodyComponent::Init(Body_Type type)
{
	_type = type;
	switch (_type)
	{
		case DYNAMIC:
		{
			Vector2 bodyPosition = { _object->GetTrans()->GetPos().x / 2.f, _object->GetTrans()->GetPos().y / 2.f };
			bodyPosition = Convert(bodyPosition);

			b2BodyDef bodyDef;
			bodyDef.type = b2BodyType::b2_dynamicBody; //static�� ������ ����,dynamic�� ������
			bodyDef.userData = _object;
			bodyDef.position.Set(bodyPosition.x, bodyPosition.y);
			_body = BOXWORLDMANAGER->GetWorld()->CreateBody(&bodyDef);  //bodyDef�� ������ �������� body�� ����

			Vector2 bodySize = { _object->GetTrans()->GetScale().x / 2.f,_object->GetTrans()->GetScale().y / 2.f };
			bodySize = Convert(bodySize);

			b2PolygonShape shape;
			shape.SetAsBox(bodySize.x, bodySize.y);

			b2FixtureDef fixture;
			fixture.isSensor = false;//�浹�Լ��� ���������� �ڽ��� �о���ΰ� �ȹо���ΰ�?
			fixture.shape = &shape;
			_body->CreateFixture(&fixture);

			break;
		}

		case STATIC:
		{
			Vector2 bodyPosition = { _object->GetTrans()->GetPos().x / 2.f, _object->GetTrans()->GetPos().y / 2.f };
			bodyPosition = Convert(bodyPosition);

			b2BodyDef bodyDef;
			bodyDef.userData = _object;
			bodyDef.position.Set(bodyPosition.x, bodyPosition.y);
			_body = BOXWORLDMANAGER->GetWorld()->CreateBody(&bodyDef);  //bodyDef�� ������ �������� body�� ����

			Vector2 bodySize = { _object->GetTrans()->GetScale().x / 2.f,_object->GetTrans()->GetScale().y / 2.f };
			bodySize = Convert(bodySize);

			b2PolygonShape shape;
			shape.SetAsBox(bodySize.x, bodySize.y);

			b2FixtureDef fixture;
			fixture.isSensor = false;//�浹�Լ��� ���������� �ڽ��� �о���ΰ� �ȹо���ΰ�?
			fixture.shape = &shape;
			_body->CreateFixture(&fixture);

			break;
		}

		case KINEMATIC:
		{
			Vector2 bodyPosition = { _object->GetTrans()->GetPos().x / 2.f, _object->GetTrans()->GetPos().y / 2.f };
			bodyPosition = Convert(bodyPosition);

			b2BodyDef bodyDef;
			bodyDef.type = b2BodyType::b2_kinematicBody; //static�� ������ ����,dynamic�� ������
			bodyDef.userData = _object;
			bodyDef.position.Set(bodyPosition.x, bodyPosition.y);
			_body = BOXWORLDMANAGER->GetWorld()->CreateBody(&bodyDef);  //bodyDef�� ������ �������� body�� ����

			Vector2 bodySize = { _object->GetTrans()->GetScale().x / 2.f,_object->GetTrans()->GetScale().y / 2.f };
			bodySize = Convert(bodySize);

			b2PolygonShape shape;
			shape.SetAsBox(bodySize.x, bodySize.y);

			b2FixtureDef fixture;
			fixture.isSensor = false;//�浹�Լ��� ���������� �ڽ��� �о���ΰ� �ȹо���ΰ�?
			fixture.shape = &shape;
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
	return Vector2(_body->GetPosition().x * 100, _body->GetPosition().y * 100);
}

Vector2 PhysicsBodyComponent::Convert(Vector2 origin)
{
	return Vector2(origin.x*0.01f, origin.y*0.01f);
}
