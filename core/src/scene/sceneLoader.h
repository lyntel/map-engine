#pragma once

#include <string>
#include <vector>
#include <memory>
#include "style/styleParamMap.h"

/* Forward Declaration of yaml-cpp node type */
namespace YAML {
    class Node;
}

namespace Tangram {

class Scene;
class TileManager;
class SceneLayer;
class View;
class ShaderProgram;
class Material;
struct MaterialTexture;
struct Filter;

class SceneLoader {

    void loadSources(YAML::Node sources, TileManager& tileManager);
    void loadLights(YAML::Node lights, Scene& scene);
    void loadCameras(YAML::Node cameras, View& view);
    void loadLayers(YAML::Node layers, Scene& scene, TileManager& tileManager);
    void parseStyleProps(YAML::Node styleProps, StyleParamMap& paramMap, const std::string& propPrefix = "");
    void loadStyles(YAML::Node styles, Scene& scene);
    void loadTextures(YAML::Node textures, Scene& scene);
    void loadMaterial(YAML::Node matNode, Material& material, Scene& scene);
    void loadShaderConfig(YAML::Node shaders, ShaderProgram& shader);
    SceneLayer loadSublayer(YAML::Node layer, const std::string& name, Scene& scene);
    MaterialTexture loadMaterialTexture(YAML::Node matCompNode, Scene& scene);
    Filter generateAnyFilter(YAML::Node filter);
    Filter generateNoneFilter(YAML::Node filter);
    Filter generatePredicate(YAML::Node filter, std::string _key);

public:

    SceneLoader() {};

    virtual ~SceneLoader() {};

    void loadScene(const std::string& _file, Scene& _scene, TileManager& _tileManager, View& _view);

    Tangram::Filter generateFilter(YAML::Node filter);
};

}