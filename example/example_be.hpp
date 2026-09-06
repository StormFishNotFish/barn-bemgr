/*
File From BarnUI/label.hpp
*/
/**
 * @file name.hpp
 * @author somebody
 * @brief ...
 * @date ...
 * @version ...
 */
#ifndef __barnext_extname__impl
#define __barnext_extname__impl
//#include<...>
/**
 * @brief ...
 */
struct NameData : public SomeData{
//...
};
/**
 * @brief Cleanup function of name widget
 * 
 * @param ctx Current UI Context
 * @param wid Current widget pointer
 */
void LabelCF(UIContext *ctx, Widget *wid) {
	LabelData *pData = (LabelData*)wid->pData;
	SDL_DestroyTexture(pData->pTexture);
	pData->pTexture = NULL;
}
/**
 * @brief Initial function of name widget
 * 
 * @param ctx Current UI Context
 * @param wid Current widget pointer
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
 * @brief Render function of name widget
 * 
 * @param ctx Current UI Context
 * @param wid Current widget pointer
 */
void LabelRF(UIContext *ctx, Widget *wid) {
	BackgroundRF(ctx, wid);
	TextRF(ctx, wid);
}
/**
 * @brief Handle Event function of name widget
 *
 * @param ctx Current UI Context
 * @param wid Current widget pointer
 * @param ev Current event struct
*/
void LabelHEF(UIContext *ctx, Widget *wid, SDL_Event *ev) {

}
/**
 * @brief Some method render/handle event/cleanup/init functions
 * 
 * @param ctx Current UI Context
 * @param wid Current widget pointer
 */
void TextRF(UIContext *ctx, Widget *wid) {
	LabelData *pData = (LabelData*)wid->pData;
	SDL_RenderTexture(ctx->pRenderer, pData->pTexture, 0, &pData->xyhws[BARNUI_LABEL_XYHW_LAYER]);
}
#endif
