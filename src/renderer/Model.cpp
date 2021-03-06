#include <iostream>
#include "blackcomb/renderer/Model.h"

namespace blackcomb::renderer {
    Model::Model(Mesh mesh, Texture texture) : mesh(mesh), texture(texture) {}

    Model::Model() : mesh(Mesh(std::vector<float>{}, {})), texture(Texture(MissingTextureFilename)) {}

    void Model::cleanup() {
        mesh.cleanup();
    }

    /**
     * Draw the model.
     */
    void Model::render() {
        texture.bind();
        mesh.render();
        texture.unbind();
    }
}
