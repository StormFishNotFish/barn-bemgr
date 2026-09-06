/*
File From BarnUI/label.hpp
*/
/**
 * @file label.hpp
 * @author StormfishChi
 * @brief Label控件头文件
 * @date 2026-8-31
 * @version v0.1
 */
#ifndef __barnui_label__impl
#define __barnui_label__impl
#include "baserender.hpp"
#include <string>
#include <SDL3_ttf/SDL_ttf.h>
/**
 * @brief Label控件的属性结构体
 */
struct LabelData : public WidgetData{
	std::string text;/**< Label内容 @note EXTERNAL*/
	TTF_Font *pFont;/**< 字体指针 @note EXTERNAL*/
	SDL_Texture *pTexture;/**< 生成的字符串纹理指针 @note INTERNAL*/
};
/**
 * @brief Label控件的清理函数
 * 
 * @param ctx 当前UIContext
 * @param wid 当前控件指针
 * @note 此函数不需要手动调用！
 */
void LabelCF(UIContext *ctx, Widget *wid) {
	LabelData *pData = (LabelData*)wid->pData;
	SDL_DestroyTexture(pData->pTexture);
	pData->pTexture = NULL;
}
/**
 * @brief Label控件的初始化函数
 * 
 * @param ctx 当前UIContext
 * @param wid 当前控件指针
 * @note 此函数仅在更改字符串内容时手动调用！
 */
void LabelIF(UIContext *ctx, Widget *wid) {
	LabelData *pData = (LabelData*)wid->pData;
	if(pData->pTexture){
		LabelCF(ctx, wid);
	}
	SDL_Surface *pSurface = TTF_RenderText_Blended(pData->pFont, pData->text.c_str(), 0, pData->fgColor);
	pData->pTexture = SDL_CreateTextureFromSurface(ctx->pRenderer, pSurface);
	SDL_DestroySurface(pSurface);
}
/**
 * @brief Label文字的绘制函数
 *  
 * @param ctx 当前UIContext
 * @param wid 当前控件指针
 */
void TextRF(UIContext *ctx, Widget *wid) {
	LabelData *pData = (LabelData*)wid->pData;
	SDL_RenderTexture(ctx->pRenderer, pData->pTexture, 0, &pData->xyhws[BARNUI_LABEL_XYHW_LAYER]);
}
/**
 * @brief Label控件的绘制函数
 * 
 * @param ctx 当前UIContext
 * @param wid 当前控件指针
 * @note 此函数不需要手动调用！
 */
void LabelRF(UIContext *ctx, Widget *wid) {
	BackgroundRF(ctx, wid);
	TextRF(ctx, wid);
}
#endif
