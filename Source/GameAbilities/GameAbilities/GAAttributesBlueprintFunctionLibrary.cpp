// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "GameAbilities.h"

#include "IGAAbilities.h"
#include "GAAttributesBase.h"
#include "GAAbilitiesComponent.h"

#include "GAAttributesBlueprintFunctionLibrary.h"



UGAAttributesBlueprintFunctionLibrary::UGAAttributesBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

bool UGAAttributesBlueprintFunctionLibrary::EqualAttribute(const FGAAttribute& Compare, FGAAttribute Against)
{
	return Compare == Against;
}
FName UGAAttributesBlueprintFunctionLibrary::GetAttribute(FGAAttribute AttributeIn)
{
	return AttributeIn.AttributeName;
}
float UGAAttributesBlueprintFunctionLibrary::GetFinalAttributeValue(AActor* Target, FGAAttribute Name)
{
	IIGAAbilities* attributeInt = Cast<IIGAAbilities>(Target);
	if (!attributeInt)
		return 0;
	if (!attributeInt->GetAttributes())
		return 0;

	return attributeInt->GetAttributes()->GetFinalAttributeValue(Name);
}
float UGAAttributesBlueprintFunctionLibrary::GetCurrentAttributeValue(AActor* Target, FGAAttribute Name)
{
	IIGAAbilities* attributeInt = Cast<IIGAAbilities>(Target);
	if (!attributeInt)
		return 0;
	return attributeInt->GetAttributes()->GetCurrentAttributeValue(Name);
}
float UGAAttributesBlueprintFunctionLibrary::GetAttributeFloat(AActor* Target, FGAAttribute AttributeIn)
{
	IIGAAbilities* attributeInt = Cast<IIGAAbilities>(Target);
	if (!attributeInt)
		return 0;

	return  attributeInt->GetAttributes()->GetFloatValue(AttributeIn);
}