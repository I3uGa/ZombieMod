#pragma once

#include "platform.h"
#include "vector.h"
#include <vector>

// Forward declarations to keep compile times down
class CCSPlayerController;

class SphereEntity
{
public:
	SphereEntity(const Vector& center, int radius);

	// Accessors (C#-style properties)
	const Vector& GetCenterPoint() const;
	void SetCenterPoint(const Vector& v);

	int GetRadius() const;
	void SetRadius(int r);

	std::vector<CCSPlayerController*>& Players();
	const std::vector<CCSPlayerController*>& Players() const;

	const std::vector<Vector>& CircleOuterPoints() const;
	const std::vector<Vector>& CircleInnerPoints() const;

	bool CollidesWithPoint(const Vector& point) const;

	static float Vector3DistanceSquared(const Vector& a, const Vector& b);

private:
	static std::vector<Vector> CalculateCirclePoints(
		const Vector& center,
		float radius,
		int numberOfPoints);

	void RecalcCircles();

private:
	Vector m_centerPoint;
	int m_radius{1};

	std::vector<CCSPlayerController*> m_players;

	std::vector<Vector> m_circleOuterPoints;
	std::vector<Vector> m_circleInnerPoints;
};