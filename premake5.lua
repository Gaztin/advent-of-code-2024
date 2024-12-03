local common = require "common"

workspace "Advent of Code 2024" do
	configurations { "Debug", "Release" }
	common.add_from_source()
end
