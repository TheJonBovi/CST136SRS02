// Code borrowed from Mitch Besser https://github.com/labermt/CST126SRS03 
//
#pragma once
#include "gps.h"
#include <type_traits>

class Boat;

class Chart
{
public:
	enum class Feature
	{
		kUnkn,
		kLand,
		kShal,
		kDeep,
		kStrt,
		kStop
	};

private:
	Feature map_[20][10];
	GPS const pathMarkers_[6]{ GPS(3,4), GPS(3,8),
								GPS(18,8), GPS(18,3),
								GPS(11,3), GPS(11,4) };

private:
	static constexpr auto latExtent{ std::extent<decltype(Chart::map_), GPS::Coordinate::kLat>::value };
	static constexpr auto lngExtent{ std::extent<decltype(Chart::map_), GPS::Coordinate::kLng>::value };

public:
	Chart() noexcept;

public:
	static Chart& getInstance()
	{
		static Chart instance;
		return instance;
	}

public:
	void setFeature(int lat, int lng, const Feature feature) noexcept;
	void setFeature(const GPS gps, const Feature feature) noexcept;

	Feature getFeature(int lat, int lng) const noexcept;
	Feature getFeature(GPS gps) const noexcept;

	GPS getMarker(const unsigned marker) const noexcept;

};

