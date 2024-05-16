#pragma once
class BaseConfig
{
public:
	virtual ~BaseConfig() = default;
	BaseConfig& operator=(const BaseConfig&) = delete;
};

