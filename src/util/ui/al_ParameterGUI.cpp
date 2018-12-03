#include <string>

#include "al/util/ui/al_ParameterGUI.hpp"

using namespace al;
using namespace std;

void ParameterGUI::drawParameterMeta(ParameterMeta *param, string suffix)
{
    drawParameterMeta(std::vector<ParameterMeta *>{param}, suffix);
}

void ParameterGUI::drawParameter(Parameter * param, std::string suffix)
{
    drawParameter(std::vector<Parameter *>{param}, suffix);
}

void ParameterGUI::drawParameterString(ParameterString *param, string suffix)
{
    drawParameterString(std::vector<ParameterString *>{param}, suffix);
}

void ParameterGUI::drawParameterInt(ParameterInt *param, string suffix)
{
    drawParameterInt(std::vector<ParameterInt *>{param}, suffix);
}

void ParameterGUI::drawParameterBool(ParameterBool * param, std::string suffix)
{
    drawParameterBool(std::vector<ParameterBool *>{param}, suffix);
}

void ParameterGUI::drawParameterPose(ParameterPose *pose, std::string suffix)
{
    drawParameterPose(std::vector<ParameterPose *>{pose}, suffix);
}

void ParameterGUI::drawParameterColor(ParameterColor *param, std::string suffix)
{
    drawParameterColor(std::vector<ParameterColor *>{param}, suffix);
}

void ParameterGUI::drawMenu(ParameterMenu * param, std::string suffix)
{
    drawMenu(std::vector<ParameterMenu *>{param}, suffix);
}

void ParameterGUI::drawChoice(ParameterChoice * param, std::string suffix)
{
    drawChoice(std::vector<ParameterChoice *>{param}, suffix);
}

void ParameterGUI::drawVec3(ParameterVec3 *param, string suffix)
{
    drawVec3(std::vector<ParameterVec3 *>{param}, suffix);
}

void ParameterGUI::drawVec4(ParameterVec4 *param, string suffix)
{
    drawVec4(std::vector<ParameterVec4 *>{param}, suffix);
}

void ParameterGUI::drawParameterMeta(std::vector<ParameterMeta *> params, string suffix, int index)
{
    assert(params.size() > 0);

    if (strcmp(typeid(*params[index]).name(), typeid(ParameterBool).name() ) == 0) { // ParameterBool
        std::vector<ParameterBool *> bools;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                bools.push_back(dynamic_cast<ParameterBool *>(p));
            } else {
                index--;
            }
        }
        drawParameterBool(bools, suffix, index);
    } else if (strcmp(typeid(*params[index]).name(), typeid(Parameter).name()) == 0) {// Parameter
        std::vector<Parameter *> ps;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                ps.push_back(dynamic_cast<Parameter *>(p));
            } else {
                index--;
            }
        }
        drawParameter(ps, suffix, index);
    } else if (strcmp(typeid(*params[index]).name(), typeid(ParameterString).name()) == 0) {// ParameterString
        std::vector<ParameterString *> ps;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                ps.push_back(dynamic_cast<ParameterString *>(p));
            } else {
                index--;
            }
        }
        drawParameterString(ps, suffix, index);
    } else if (strcmp(typeid(*params[index]).name(), typeid(ParameterInt).name()) == 0) {// ParameterInt
        std::vector<ParameterInt *> ps;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                ps.push_back(dynamic_cast<ParameterInt *>(p));
            } else {
                index--;
            }
        }
        drawParameterInt(ps, suffix, index);
    } else if (strcmp(typeid(*params[index]).name(), typeid(ParameterPose).name()) == 0) {// ParameterPose
        std::vector<ParameterPose *> poses;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                poses.push_back(dynamic_cast<ParameterPose *>(p));
            } else {
                index--;
            }
        }
        drawParameterPose(poses, suffix, index);
    } else if (strcmp(typeid(*params[index]).name(), typeid(ParameterMenu).name()) == 0) {// ParameterMenu
        std::vector<ParameterMenu *> menus;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                menus.push_back(dynamic_cast<ParameterMenu *>(p));
            } else {
                index--;
            }
        }
        drawMenu(menus, suffix, index);
    } else if (strcmp(typeid(*params[index]).name(), typeid(ParameterChoice).name()) == 0) {// ParameterChoice
        std::vector<ParameterChoice *> choices;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                choices.push_back(dynamic_cast<ParameterChoice *>(p));
            } else {
                index--;
            }
        }
        drawChoice(choices, suffix, index);
    } else if (strcmp(typeid(*params[index]).name(), typeid(ParameterVec3).name()) == 0) {// ParameterVec3
        std::vector<ParameterVec3 *> vec3s;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                vec3s.push_back(dynamic_cast<ParameterVec3 *>(p));
            } else {
                index--;
            }
        }
        drawVec3(vec3s, suffix, index);
    }  else if (strcmp(typeid(*params[index]).name(), typeid(ParameterVec4).name()) == 0) {// ParameterVec4
        std::vector<ParameterVec4 *> vec4s;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                vec4s.push_back(dynamic_cast<ParameterVec4 *>(p));
            } else {
                index--;
            }
        }
        drawVec4(vec4s, suffix, index);
    } else if (strcmp(typeid(*params[index]).name(), typeid(ParameterColor).name()) == 0) {// ParameterColor
        std::vector<ParameterColor *> colors;
        for(auto *p: params) {
            if (p->getHint("hide") == 0.0) {
                colors.push_back(dynamic_cast<ParameterColor *>(p));
            } else {
                index--;
            }
        }
        drawParameterColor(colors, suffix, index);
    }
    else {
        // TODO this check should be performed on registration
        std::cout << "Unsupported Parameter type for display" << std::endl;
    }
}

void ParameterGUI::drawParameter(std::vector<Parameter *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    if (param->getHint("intcombo") == 1.0) {
        int value = (int)param->get();
        vector<string> values;
        for (float i = param->min(); i <= param->max(); i++) {
            // There's got to be a better way...
            values.push_back(to_string((int)i));
        }
        auto vector_getter = [](void* vec, int idx, const char** out_text)
        {
            auto& vector = *static_cast<std::vector<std::string>*>(vec);
            if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
            *out_text = vector.at(idx).c_str();
            return true;
        };
        if (!values.empty()) {
            bool changed = ImGui::Combo((param->displayName() + suffix).c_str(), &value, vector_getter,
                static_cast<void*>(&values), values.size());
            if (changed) {
                for (auto *p: params) {
                    p->set(value);
                }
            }
        }
    }
    else {
        float value = param->get();
        bool changed = ImGui::SliderFloat((param->displayName() + suffix).c_str(), &value, param->min(), param->max());
        if (changed) {
            for (auto *p: params) {
                p->set(value);
            }
        }
    }
}

void ParameterGUI::drawParameterString(std::vector<ParameterString *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    ImGui::Text((param->displayName() + ":").c_str());
    ImGui::SameLine();
    ImGui::Text((param->get()).c_str());

}


void ParameterGUI::drawParameterInt(std::vector<ParameterInt *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    int value = param->get();
    bool changed = ImGui::SliderInt((param->displayName() + suffix).c_str(), &value, param->min(), param->max());
    if (changed) {
        for (auto *p: params) {
            p->set(value);
        }
    }
}

void ParameterGUI::drawParameterBool(std::vector<ParameterBool *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    bool changed;
    if (param->getHint("latch") == 1.0) {
        bool value = param->get() == 1.0;
        changed = ImGui::Checkbox((param->displayName() + suffix).c_str(), &value);
        if (changed) {
            param->set(value ? 1.0 : 0.0);
        }
    }
    else {
        changed = ImGui::Button((param->displayName() + suffix).c_str());
        if (changed) {
            for (auto *p: params) {
                p->set(1.0);
            }
        } else {
            if (param->get() == 1.0) {
                for (auto *p: params) {
                    p->set(0.0);
                }
            }
        }
    }
}

void ParameterGUI::drawParameterPose(std::vector<ParameterPose *> params, std::string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &pose = params[index];
    if (ImGui::CollapsingHeader(("Pose:" + pose->displayName()).c_str(), ImGuiTreeNodeFlags_CollapsingHeader)) {
        Vec3d currentPos = pose->get().pos();
        float x = currentPos.x;
        if (ImGui::SliderFloat(("X" + suffix + pose->displayName()).c_str(), &x, -5, 5)) {
            currentPos.x = x;
            for (auto *p: params) {
                p->set(Pose(currentPos, pose->get().quat()));
            }
        }
        float y = currentPos.y;
        if (ImGui::SliderFloat(("Y" + suffix + pose->displayName()).c_str(), &y, -5, 5)) {
            currentPos.y = y;
            for (auto *p: params) {
                p->set(Pose(currentPos, pose->get().quat()));
            }
        }
        float z = currentPos.z;
        if (ImGui::SliderFloat(("Z" + suffix + pose->displayName()).c_str(), &z, -10, 0)) {
            currentPos.z = z;
            for (auto *p: params) {
                p->set(Pose(currentPos, pose->get().quat()));
            }
        }
        ImGui::Spacing();
    }
}

void ParameterGUI::drawParameterColor(std::vector<ParameterColor *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    Color c = param->get();
    ImVec4 color = ImColor(c.r, c.g, c.b, c.a);

    static bool alpha_preview = true;
    static bool alpha_half_preview = false;
    static bool drag_and_drop = true;
    static bool options_menu = true;
    static bool hdr = false;

    bool showAlpha = param->getHint("showAlpha");
    bool showHsv = param->getHint("hsv");

    int misc_flags = (!showAlpha ? ImGuiColorEditFlags_NoAlpha : 0) | (hdr ? ImGuiColorEditFlags_HDR : 0)
            | (drag_and_drop ? 0 : ImGuiColorEditFlags_NoDragDrop)
            | (alpha_half_preview ? ImGuiColorEditFlags_AlphaPreviewHalf : (alpha_preview ? ImGuiColorEditFlags_AlphaPreview : 0))
            | (options_menu ? 0 : ImGuiColorEditFlags_NoOptions)
            | (!showHsv ? 0 : ImGuiColorEditFlags_HSV);

//    ImGui::Text("Color widget HSV with Alpha:");
    if (ImGui::ColorEdit4((param->displayName() + suffix).c_str(), (float*)&color, misc_flags)) {
        c.r = color.x;
        c.g = color.y;
        c.b = color.z;
        c.a = color.w;
        for (auto *p: params) {
            p->set(c);
        }
    }
}

void ParameterGUI::drawMenu(std::vector<ParameterMenu *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    int value = param->get();
    auto values = param->getElements();
    bool changed = ImGui::Combo((param->displayName() + suffix).c_str(), &value, vector_getter,
                static_cast<void*>(&values), values.size());
    if (changed) {
        for (auto *p: params) {
            p->set(value);
        }
    }
}

void ParameterGUI::drawChoice(std::vector<ParameterChoice *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    uint16_t value = param->get();
    auto elements = param->getElements();
    if (ImGui::CollapsingHeader((param->displayName() + suffix).c_str(), ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_DefaultOpen)) {
        for (unsigned int i = 0; i < elements.size(); i++) {
            bool state = value & (1 << i);
            if (ImGui::Checkbox((elements[i] + suffix + param->getName()).c_str(), &state)) {
                std::cout << elements[i] + suffix + param->getName() << std::endl;
                value ^= (-(state) ^ value) & (1UL << i); // Set an individual bit
                for (auto *p: params) {
                    p->set(value);
                }
            }

        }
    }
}

void ParameterGUI::drawVec3(std::vector<ParameterVec3 *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    if (ImGui::CollapsingHeader((param->displayName() + suffix).c_str(), ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_DefaultOpen)) {
        Vec3f currentValue = param->get();
        float x = currentValue.elems()[0];
        bool updated = false;
        float max = 10;
        float min = -10;
        bool exists;
        float value;
        value = param->getHint("maxx", &exists);
        if (exists) { max = value; }
        value = param->getHint("minx", &exists);
        if (exists) { min = value; }
        bool changed = ImGui::SliderFloat(("X" + suffix + param->getName()).c_str(), &x, min, max);
        if (changed) {
            currentValue.x = x;
            updated = true;
        }
        float y = currentValue.elems()[1];
        max = 10;
        min = -10;
        value = param->getHint("maxy", &exists);
        if (exists) { max = value; }
        value = param->getHint("miny", &exists);
        if (exists) { min = value; }
        changed = ImGui::SliderFloat(("Y" + suffix + param->getName()).c_str(), &y, min, max);
        if (changed) {
            currentValue.y = y;
            updated = true;
        }
        float z = currentValue.elems()[2];
        max = 10;
        min = -10;
        value = param->getHint("maxz", &exists);
        if (exists) { max = value; }
        value = param->getHint("minz", &exists);
        if (exists) { min = value; }
        changed = ImGui::SliderFloat(("Z" + suffix + param->getName()).c_str(), &z, min, max);
        if (changed) {
            currentValue.z = z;
            updated = true;
        }
        if (updated) {
            for (auto *p: params) {
                p->set(currentValue);
            }
        }
    }
}

void ParameterGUI::drawVec4(std::vector<ParameterVec4 *> params, string suffix, int index)
{
    if (params.size() == 0) return;
    assert(index < (int) params.size());
    auto &param = params[index];
    if (ImGui::CollapsingHeader((param->displayName() + suffix).c_str(), ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_DefaultOpen)) {
        Vec4f currentValue = param->get();
        float x = currentValue.elems()[0];
        bool updated = false;
        bool changed = ImGui::SliderFloat(("X" + suffix + param->getName()).c_str(), &x, -10, 10);
        if (changed) {
            currentValue.x = x;
            updated = true;
        }
        float y = currentValue.elems()[1];
        changed = ImGui::SliderFloat(("Y" + suffix + param->getName()).c_str(), &y, -10, 10);
        if (changed) {
            currentValue.y = y;
            updated = true;
        }
        float z = currentValue.elems()[2];
        changed = ImGui::SliderFloat(("Z" + suffix + param->getName()).c_str(), &z, -10, 10);
        if (changed) {
            currentValue.z = z;
            updated = true;
        }
        if (updated) {
            param->set(currentValue);
        }
        float w = currentValue.elems()[3];
        changed = ImGui::SliderFloat(("W" + suffix + param->getName()).c_str(), &z, -10, 10);
        if (changed) {
            currentValue.w = w;
            updated = true;
        }
        if (updated) {
            for (auto *p: params) {
                p->set(currentValue);
            }
        }
    }
}

void ParameterGUI::drawNav(Nav *mNav, std::string suffix)
{
    if (ImGui::CollapsingHeader(("Navigation##nav" + suffix).c_str(), ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_DefaultOpen)) {
        Vec3d &currentPos = mNav->pos();
        float x = currentPos.elems()[0];

        bool changed = ImGui::SliderFloat(("X##__nav_" + suffix).c_str(), &x, -10, 10);
        if (changed) {
            currentPos.elems()[0] = x;
        }
        float y = currentPos.elems()[1];
        changed = ImGui::SliderFloat(("Y##__nav_" + suffix).c_str(), &y, -10, 10);
        if (changed) {
            currentPos.elems()[1] = y;
        }
        float z = currentPos.elems()[2];
        changed = ImGui::SliderFloat(("Z##__nav_" + suffix).c_str(), &z, -10, 10);
        if (changed) {
            currentPos.elems()[2] = z;
        }
        ImGui::Spacing();
    }
}

void ParameterGUI::drawDynamicScene(DynamicScene *scene, std::string suffix)
{
    
}


void ParameterGUI::drawPresetHandler(PresetHandler *presetHandler, int presetColumns,
                                     int presetRows, bool &storeButtonOn)
{
     if (ImGui::CollapsingHeader("Presets", ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_DefaultOpen)) {

        int selection = presetHandler->getCurrentPresetIndex();
        std::string currentPresetName =presetHandler->getCurrentPresetName();

        static std::string enteredText;
        char buf1[64];
        if (enteredText.size() == 0) {
            strncpy(buf1, currentPresetName.c_str(), 63);
        } else {
            strncpy(buf1, enteredText.c_str(), 63);
        }
        if (ImGui::InputText("preset##__Preset", buf1, 64)) {
            enteredText = buf1;
        }
        static int presetHandlerBank = 0;
        int counter = presetHandlerBank * (presetColumns * presetRows) ;
        std::string suffix = "##__Preset";
        for (int row = 0; row < presetRows; row++) {
            for (int column = 0; column < presetColumns; column++) {
                std::string name = std::to_string(counter);
                ImGui::PushID(counter);

                bool is_selected = selection == counter;
                if (is_selected) {
                    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.1, 0.1, 0.1, 1.0));
                }
                if (ImGui::Selectable((name + suffix).c_str(), is_selected, 0, ImVec2(18, 15)))
                {
                    if (storeButtonOn) {
                        std::string saveName = enteredText;
                        if (saveName.size() == 0) {
                            saveName = name;
                        }
                        presetHandler->storePreset(counter, saveName.c_str());
                        selection = counter;
                        storeButtonOn = false;
                        enteredText.clear();
                    } else {
                        if (presetHandler->recallPreset(counter) != "") { // Preset is available
                            selection = counter;
                        }
                    }
                }
                if (is_selected) {
                    ImGui::PopStyleColor(1);
                }
                if (column < presetColumns - 1) ImGui::SameLine();
                counter++;
                ImGui::PopID();
            }
        }
        ImGui::Checkbox("Store##__Preset", &storeButtonOn);
        ImGui::SameLine();
        static vector<string> seqList {"1", "2", "3", "4"};
        ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.15f);
        ImGui::Combo("Bank##__Preset", &presetHandlerBank, vector_getter, static_cast<void*>(&seqList), seqList.size());
        ImGui::SameLine();
        ImGui::PopItemWidth();
        ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.2f);
        float morphTime = presetHandler->getMorphTime();
        if (ImGui::InputFloat("morph time##__Preset", &morphTime, 0.0f, 20.0f)) {
            presetHandler->setMorphTime(morphTime);
        }
        ImGui::PopItemWidth();
//            ImGui::Text("%s", currentPresetName.c_str());

    }
}

void ParameterGUI::drawSequenceRecorder(SequenceRecorder *sequenceRecorder,
                                        bool &overwriteButtonValue)
{
    if (ImGui::CollapsingHeader("Sequence Recorder##__SequenceRecorder", ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_DefaultOpen)) {
        static char buf_seq_recorder[64] = "test"; ImGui::InputText("Record Name##__SequenceRecorder", buf_seq_recorder, 64);
        static bool button_seq_recorder_value = false;
        if (ImGui::Checkbox("Record##__SequenceRecorder", &button_seq_recorder_value)) {
            if (button_seq_recorder_value) {
                sequenceRecorder->startRecord(buf_seq_recorder, overwriteButtonValue);
            } else {
                sequenceRecorder->stopRecord();
            }
        }
        ImGui::SameLine();
        ImGui::Checkbox("Overwrite##__SequenceRecorder", &overwriteButtonValue);
    }
}


void ParameterGUI::drawBundleGroup(std::vector<ParameterBundle *> bundleGroup,
                                   string suffix,
                                   std::map<std::string, int> &currentBundle,
                                   std::map<std::string, bool> &bundleGlobal)
{
    std::string name = bundleGroup[0]->name();
    int index = currentBundle[name];

//    ImGui::Separator();

    if (ImGui::CollapsingHeader(("Bundle:" + name + suffix).c_str(), ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_DefaultOpen)) {
        if (!bundleGlobal[name]) {
//            ImGui::SameLine();
            if (ImGui::InputInt(suffix.c_str(), &index)) {
                if (index >= 0 && index < (int) bundleGroup.size()) {
                    currentBundle[name] = index;
                }
            }
            ImGui::SameLine();
        }
        ImGui::Checkbox("Global", &bundleGlobal[name]);
        suffix += "__index_" + std::to_string(index);
        if (bundleGlobal[name]) {
            // We will try to match parameters in order to the first bundle
            // Perhaps we should try to do better matching to match parameter names,
            // but for now we assume that parameters have exactly the same
            // order inside bundles to be able to group them
            for (unsigned int i = 0; i < bundleGroup[0]->parameters().size(); i++) {
                std::vector<ParameterMeta *> params;
                std::string paramName = bundleGroup[0]->parameters()[i]->getName();
                for (auto *bundle: bundleGroup) {
                    auto &parameters = bundle->parameters();
                    if (parameters[i]->getName() == paramName) {
                        params.push_back(parameters[i]);
                    }
                }
                drawParameterMeta(params, suffix, index);
            }

        } else {
            for (ParameterMeta *param: bundleGroup[currentBundle[name]]->parameters()) {
                drawParameterMeta(param, suffix);
            }
            for (auto bundle: bundleGroup[currentBundle[name]]->bundles()) {
                std::string subBundleName = bundle.first;
                if (ImGui::CollapsingHeader((subBundleName + "##" + name + subBundleName + suffix).c_str(), ImGuiTreeNodeFlags_CollapsingHeader)) {
                   for (auto *param: bundle.second->parameters()) {
                       drawParameterMeta({param}, suffix + subBundleName, 0);
                   }
                }
            }
        }
        ImGui::Separator();
    }

}