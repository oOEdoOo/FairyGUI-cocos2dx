#ifndef __GTEXTINPUT_H__
#define __GTEXTINPUT_H__

#include "cocos2d.h"
#include "FairyGUIMacros.h"
#include "GTextField.h"
#include "display/FUIInput.h"

NS_FGUI_BEGIN

class GTextInput : public GTextField, cocos2d::ui::EditBoxDelegate
{
public:
    GTextInput();
    virtual ~GTextInput();

    CREATE_FUNC(GTextInput);

    virtual bool isSingleLine() const override;
    virtual void setSingleLine(bool value) override;

    virtual TextFormat* getTextFormat() const override { return _input->getTextFormat(); }
    virtual void applyTextFormat() override;

    void setPrompt(const std::string& value);
    void setPassword(bool value);
    void setKeyboardType(int value);
    void setMaxLength(int value);
    void setRestrict(const std::string& value);

    // 设置回调，给lua使用
    // itemRenderer
    int onSubmitCallback = -1;
    void setOnSubmit(int luaCallback);
    
    void setString(std::string content)
    {
        this->setText(content);
    };
    
    std::string getString()
    {
        return this->getText();
    }
    
    void setTextSingleLine(bool isSingleLine)
    {
        this->setSingleLine(isSingleLine);
    }
protected:
    // onSubmit中调用lua函数
    void onSubmit(EventContext *context);
    virtual void handleInit() override;
    virtual void handleSizeChanged() override;
    virtual void setup_beforeAdd(ByteBuffer* buffer, int beginPos) override;

    virtual void setTextFieldText() override;

    virtual void editBoxReturn(cocos2d::ui::EditBox* editBox) override;
    virtual void editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text) override;

private:
    FUIInput* _input;
};

NS_FGUI_END

#endif
