#include "sphereentity.h"
#include <cmath>

SphereEntity::SphereEntity(const Vector& center, int radius) :
	m_centerPoint(center), m_radius(radius)
{
	m_players.reserve(16);

	RecalcCircles();
}

const Vector& SphereEntity::GetCenterPoint() const
{
	return m_centerPoint;
}

void SphereEntity::SetCenterPoint(const Vector& v)
{
	m_centerPoint = v;
	RecalcCircles();
}

int SphereEntity::GetRadius() const
{
	return m_radius;
}

void SphereEntity::SetRadius(int r)
{
	m_radius = r;
	RecalcCircles();
}

std::vector<CCSPlayerController*>& SphereEntity::Players()
{
	return m_players;
}

const std::vector<CCSPlayerController*>& SphereEntity::Players() const
{
	return m_players;
}

const std::vector<Vector>& SphereEntity::CircleOuterPoints() const
{
	return m_circleOuterPoints;
}

const std::vector<Vector>& SphereEntity::CircleInnerPoints() const
{
	return m_circleInnerPoints;
}

bool SphereEntity::CollidesWithPoint(const Vector& point) const
{
	const float distSq = Vector3DistanceSquared(m_centerPoint, point);
	const float radiusSq = static_cast<float>(m_radius * m_radius);
	return distSq < radiusSq;
}

float SphereEntity::Vector3DistanceSquared(const Vector& a, const Vector& b)
{
	const float dx = a.x - b.x;
	const float dy = a.y - b.y;
	const float dz = a.z - b.z;
	return dx * dx + dy * dy + dz * dz;
}

std::vector<Vector> SphereEntity::CalculateCirclePoints(
	const Vector& center,
	float radius,
	int numberOfPoints)
{
	std::vector<Vector> points;
	points.resize(static_cast<size_t>(numberOfPoints));

	constexpr float kPi = 3.14159265358979323846f;

	for (int i = 0; i < numberOfPoints; ++i)
	{
		const float theta = 2.0f * kPi * static_cast<float>(i) / static_cast<float>(numberOfPoints);

		points[static_cast<size_t>(i)] =
			center + Vector(radius * std::cos(theta), radius * std::sin(theta), 0.0f);
	}

	return points;
}

void SphereEntity::RecalcCircles()
{
	m_circleOuterPoints = CalculateCirclePoints(
		m_centerPoint,
		static_cast<float>(m_radius),
		360);

	m_circleInnerPoints = CalculateCirclePoints(
		m_centerPoint,
		static_cast<float>(m_radius - 25),
		360);
}