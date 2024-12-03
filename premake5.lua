local common = require "common"
local days = require "days"

workspace "Advent of Code 2024" do
	configurations { "Debug", "Release" }
	common.add_from_source()
	for i, day in ipairs(days) do
		day.add_from_source(common)
	end
end
