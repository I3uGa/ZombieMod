#pragma once

#include "platform.h"
#include "vector.h"
#include <vector>
#include "entity/cbasemodelentity.h"
#include "entity/globaltypes.h"

class CBeam : public CBaseModelEntity
{
public:
	DECLARE_SCHEMA_CLASS(CBeam)

	SCHEMA_FIELD(float, m_flFrameRate)
	SCHEMA_FIELD(float, m_flHDRColorScale) // 0 = color, 1 = color temperature
	SCHEMA_FIELD(float, m_flFireTime)
	SCHEMA_FIELD(float, m_flDamage) // default 6500
	SCHEMA_FIELD(int, m_nNumBeamEnts)
	SCHEMA_FIELD(int, m_nBeamFlags) // Shadowmap size in pixels (512 is a good starting value)
	SCHEMA_FIELD(float, m_fWidth)
	SCHEMA_FIELD(float, m_fEndWidth)
	SCHEMA_FIELD(float, m_fFadeLength)
	SCHEMA_FIELD(float, m_fHaloScale)  // Falloff over the range
	SCHEMA_FIELD(float, m_fAmplitude) // Falloff from the source
	SCHEMA_FIELD(float, m_fStartFrame)
	SCHEMA_FIELD(float, m_fSpeed)
	SCHEMA_FIELD(float, m_flFrame)
	SCHEMA_FIELD(bool, m_bTurnedOff)
	SCHEMA_FIELD(Vector, m_vecEndPos)
	SCHEMA_FIELD(int, m_nDissolveType)

};

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