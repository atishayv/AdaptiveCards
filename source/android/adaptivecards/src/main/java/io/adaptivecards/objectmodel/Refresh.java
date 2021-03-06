/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class Refresh {
  private transient long swigCPtr;
  private transient boolean swigCMemOwn;

  protected Refresh(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Refresh obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void swigSetCMemOwn(boolean own) {
    swigCMemOwn = own;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_Refresh(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public Refresh() {
    this(AdaptiveCardObjectModelJNI.new_Refresh__SWIG_0(), true);
  }

  public Refresh(BaseActionElement action, StringVector userIds) {
    this(AdaptiveCardObjectModelJNI.new_Refresh__SWIG_1(BaseActionElement.getCPtr(action), action, StringVector.getCPtr(userIds), userIds), true);
  }

  public BaseActionElement GetAction() {
    long cPtr = AdaptiveCardObjectModelJNI.Refresh_GetAction__SWIG_0(swigCPtr, this);
    return (cPtr == 0) ? null : new BaseActionElement(cPtr, true);
  }

  public void SetAction(BaseActionElement arg0) {
    AdaptiveCardObjectModelJNI.Refresh_SetAction(swigCPtr, this, BaseActionElement.getCPtr(arg0), arg0);
  }

  public StringVector GetUserIds() {
    return new StringVector(AdaptiveCardObjectModelJNI.Refresh_GetUserIds__SWIG_0(swigCPtr, this), false);
  }

  public void SetUserIds(StringVector arg0) {
    AdaptiveCardObjectModelJNI.Refresh_SetUserIds(swigCPtr, this, StringVector.getCPtr(arg0), arg0);
  }

  public boolean ShouldSerialize() {
    return AdaptiveCardObjectModelJNI.Refresh_ShouldSerialize(swigCPtr, this);
  }

  public String Serialize() {
    return AdaptiveCardObjectModelJNI.Refresh_Serialize(swigCPtr, this);
  }

  public JsonValue SerializeToJsonValue() {
    return new JsonValue(AdaptiveCardObjectModelJNI.Refresh_SerializeToJsonValue(swigCPtr, this), true);
  }

  public static Refresh Deserialize(ParseContext context, JsonValue json) {
    long cPtr = AdaptiveCardObjectModelJNI.Refresh_Deserialize(ParseContext.getCPtr(context), context, JsonValue.getCPtr(json), json);
    return (cPtr == 0) ? null : new Refresh(cPtr, true);
  }

  public static Refresh DeserializeFromString(ParseContext context, String jsonString) {
    long cPtr = AdaptiveCardObjectModelJNI.Refresh_DeserializeFromString(ParseContext.getCPtr(context), context, jsonString);
    return (cPtr == 0) ? null : new Refresh(cPtr, true);
  }

}
