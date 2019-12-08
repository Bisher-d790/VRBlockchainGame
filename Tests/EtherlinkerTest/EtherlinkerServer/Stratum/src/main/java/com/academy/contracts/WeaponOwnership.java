package com.academy.contracts;

import io.reactivex.Flowable;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.Callable;
import org.web3j.abi.EventEncoder;
import org.web3j.abi.TypeReference;
import org.web3j.abi.datatypes.Address;
import org.web3j.abi.datatypes.Bool;
import org.web3j.abi.datatypes.DynamicArray;
import org.web3j.abi.datatypes.Event;
import org.web3j.abi.datatypes.Function;
import org.web3j.abi.datatypes.Type;
import org.web3j.abi.datatypes.Utf8String;
import org.web3j.abi.datatypes.generated.Uint16;
import org.web3j.abi.datatypes.generated.Uint256;
import org.web3j.abi.datatypes.generated.Uint32;
import org.web3j.crypto.Credentials;
import org.web3j.protocol.Web3j;
import org.web3j.protocol.core.DefaultBlockParameter;
import org.web3j.protocol.core.RemoteCall;
import org.web3j.protocol.core.methods.request.EthFilter;
import org.web3j.protocol.core.methods.response.Log;
import org.web3j.protocol.core.methods.response.TransactionReceipt;
import org.web3j.tuples.generated.Tuple7;
import org.web3j.tx.Contract;
import org.web3j.tx.TransactionManager;
import org.web3j.tx.gas.ContractGasProvider;

/**
 * <p>Auto generated code.
 * <p><strong>Do not modify!</strong>
 * <p>Please use the <a href="https://docs.web3j.io/command_line.html">web3j command line tools</a>,
 * or the org.web3j.codegen.SolidityFunctionWrapperGenerator in the 
 * <a href="https://github.com/web3j/web3j/tree/master/codegen">codegen module</a> to update.
 *
 * <p>Generated with web3j version 4.1.0.
 */
public class WeaponOwnership extends Contract {
    private static final String BINARY = "608060408190526010600155662386f26fc1000060025566038d7ea4c6800060065560008054600160a060020a0319163317808255600160a060020a0316917f8be0079c531659141344cd1fd0a4f28419497f9722a3daafe3b4186f6b6457e0908290a36110a8806100726000396000f3006080604052600436106100fb5763ffffffff7c01000000000000000000000000000000000000000000000000000000006000350416630187fcf38114610100578063095ea7b3146101715780630ce90ec21461018a5780631e3b38221461019557806323b872dd146101c95780633a0c713a146101e65780633ccfd60b14610201578063555e73c8146102165780636352211e146102e357806370a08231146102fb578063715018a61461032e5780638da5cb5b146103435780638f32d59b146103585780639e41b73f14610381578063c39cbef114610399578063c4b53535146103bd578063ccf670f814610418578063f2fde38b14610430575b600080fd5b34801561010c57600080fd5b50610121600160a060020a0360043516610451565b60408051602080825283518183015283519192839290830191858101910280838360005b8381101561015d578181015183820152602001610145565b505050509050019250505060405180910390f35b610188600160a060020a036004351660243561050f565b005b61018860043561059b565b3480156101a157600080fd5b506101ad600435610621565b60408051600160a060020a039092168252519081900360200190f35b610188600160a060020a036004358116906024351660443561063c565b3480156101f257600080fd5b50610188600435602435610692565b34801561020d57600080fd5b5061018861071b565b34801561022257600080fd5b5061022e600435610775565b60408051602080820189905263ffffffff8089169383019390935291861660608201526080810185905261ffff80851660a0830152831660c082015260e08082528951908201528851909182916101008301918b019080838360005b838110156102a257818101518382015260200161028a565b50505050905090810190601f1680156102cf5780820380516001836020036101000a031916815260200191505b509850505050505050505060405180910390f35b3480156102ef57600080fd5b506101ad600435610861565b34801561030757600080fd5b5061031c600160a060020a036004351661087c565b60408051918252519081900360200190f35b34801561033a57600080fd5b50610188610897565b34801561034f57600080fd5b506101ad610901565b34801561036457600080fd5b5061036d610911565b604080519115158252519081900360200190f35b34801561038d57600080fd5b5061022e600435610922565b3480156103a557600080fd5b50610188600480359060248035908101910135610a89565b3480156103c957600080fd5b506040805160206004803580820135601f81018490048402850184019095528484526101889436949293602493928401919081908401838280828437509497505093359450610b1a9350505050565b34801561042457600080fd5b50610188600435610d6e565b34801561043c57600080fd5b50610188600160a060020a0360043516610d86565b6060806000806005600086600160a060020a0316600160a060020a03168152602001908152602001600020546040519080825280602002602001820160405280156104a6578160200160208202803883390190505b50925060009150600090505b60035481101561050657600081815260046020526040902054600160a060020a03868116911614156104fe578083838151811015156104ed57fe5b602090810290910101526001909101905b6001016104b2565b50909392505050565b6000818152600460205260409020548190600160a060020a0316331461053457600080fd5b600082815260076020526040808220805473ffffffffffffffffffffffffffffffffffffffff1916600160a060020a0387169081179091559051849233917f8c5be1e5ebec7d5bd14f71427d1e84f3dd0314c0f7b2291e5b200ac8c7c3b9259190a4505050565b60065434146105a957600080fd5b6105e160016003838154811015156105bd57fe5b600091825260209091206002600590920201015463ffffffff9081169190610da516565b60038054839081106105ef57fe5b906000526020600020906005020160020160006101000a81548163ffffffff021916908363ffffffff16021790555050565b600460205260009081526040902054600160a060020a031681565b600081815260046020526040902054600160a060020a03163314806106775750600081815260076020526040902054600160a060020a031633145b151561068257600080fd5b61068d838383610dc4565b505050565b601482816003828154811015156106a557fe5b600091825260209091206002600590920201015463ffffffff1610156106ca57600080fd5b6000848152600460205260409020548490600160a060020a031633146106ef57600080fd5b836003868154811015156106ff57fe5b9060005260206000209060050201600101819055505050505050565b6000610725610911565b151561073057600080fd5b610738610901565b604051909150600160a060020a03821690303180156108fc02916000818181858888f19350505050158015610771573d6000803e3d6000fd5b5050565b600380548290811061078357fe5b60009182526020918290206005919091020180546040805160026001841615610100026000190190931692909204601f81018590048502830185019091528082529193509183919083018282801561081c5780601f106107f15761010080835404028352916020019161081c565b820191906000526020600020905b8154815290600101906020018083116107ff57829003601f168201915b5050506001840154600285015460038601546004909601549495919463ffffffff8083169550640100000000909204909116925061ffff808216916201000090041687565b600090815260046020526040902054600160a060020a031690565b600160a060020a031660009081526005602052604090205490565b61089f610911565b15156108aa57600080fd5b60008054604051600160a060020a03909116907f8be0079c531659141344cd1fd0a4f28419497f9722a3daafe3b4186f6b6457e0908390a36000805473ffffffffffffffffffffffffffffffffffffffff19169055565b600054600160a060020a03165b90565b600054600160a060020a0316331490565b6060600080600080600080610935610f3a565b600380548a90811061094357fe5b6000918252602091829020604080516005939093029091018054600260018216156101009081026000190190921604601f81018690049095028401810190925260e08301848152929390928492909184918401828280156109e55780601f106109ba576101008083540402835291602001916109e5565b820191906000526020600020905b8154815290600101906020018083116109c857829003601f168201915b50505091835250506001820154602080830191909152600283015463ffffffff80821660408086019190915264010000000090920416606080850191909152600385015460808086019190915260049095015461ffff80821660a080880191909152620100009092041660c095860152865193870151928701519187015195870151908701519690940151929f919e509c50929a5090985091965090945092505050565b60028381600382815481101515610a9c57fe5b600091825260209091206002600590920201015463ffffffff161015610ac157600080fd5b6000858152600460205260409020548590600160a060020a03163314610ae657600080fd5b8484600388815481101515610af757fe5b60009182526020909120610b119360059092020191610f76565b50505050505050565b6000610b24610911565b1515610b2f57600080fd5b6040805160e081018252848152602080820185905260019282018390524263ffffffff16606083015260146080830152600060a0830181905260c0830181905260038054808601808355919092528351805191949360059093027fc2575a0e9e593c00f959f8c92f12db2869c3395a3b0502d05e2516446f71f85b0192610bbb92849290910190610ff4565b50602082810151600183810191909155604080850151600285018054606088015163ffffffff1990911663ffffffff9384161767ffffffff000000001916640100000000918416919091021790556080860151600386015560a08601516004958601805460c09098015161ffff1990981661ffff9283161763ffff000019166201000092909816919091029690961790955595909403600081815292825285832080543373ffffffffffffffffffffffffffffffffffffffff1990911681179091558352600590915293902054929350610c97929190610e9c16565b6005600033600160a060020a0316600160a060020a03168152602001908152602001600020819055507f9d26e4755409d8cdc484d7a47f131ce8ef4e26c993833d9e0b58fa7a930fdb6d8184846040518084815260200180602001838152602001828103825284818151815260200191508051906020019080838360005b83811015610d2d578181015183820152602001610d15565b50505050905090810190601f168015610d5a5780820380516001836020036101000a031916815260200191505b5094505050505060405180910390a1505050565b610d76610911565b1515610d8157600080fd5b600655565b610d8e610911565b1515610d9957600080fd5b610da281610eab565b50565b600082820163ffffffff8085169082161015610dbd57fe5b9392505050565b600160a060020a038216600090815260056020526040902054610dee90600163ffffffff610e9c16565b600160a060020a038316600090815260056020526040808220929092553381522054610e2190600163ffffffff610f2816565b3360009081526005602090815260408083209390935583825260049052818120805473ffffffffffffffffffffffffffffffffffffffff1916600160a060020a038681169182179092559251849392918716917fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef91a4505050565b600082820183811015610dbd57fe5b600160a060020a0381161515610ec057600080fd5b60008054604051600160a060020a03808516939216917f8be0079c531659141344cd1fd0a4f28419497f9722a3daafe3b4186f6b6457e091a36000805473ffffffffffffffffffffffffffffffffffffffff1916600160a060020a0392909216919091179055565b600082821115610f3457fe5b50900390565b6040805160e081018252606080825260006020830181905292820183905281018290526080810182905260a0810182905260c081019190915290565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f10610fb75782800160ff19823516178555610fe4565b82800160010185558215610fe4579182015b82811115610fe4578235825591602001919060010190610fc9565b50610ff0929150611062565b5090565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f1061103557805160ff1916838001178555610fe4565b82800160010185558215610fe4579182015b82811115610fe4578251825591602001919060010190611047565b61090e91905b80821115610ff057600081556001016110685600a165627a7a7230582040b1ef126925a76ce5233a08918ee4f385ec80fdd8bc5757308d50c79eac55a60029";

    public static final String FUNC_GETWEAPONBYOWNER = "getWeaponByOwner";

    public static final String FUNC_APPROVE = "approve";

    public static final String FUNC_LEVELUP = "levelUp";

    public static final String FUNC_WEAPONTOOWNER = "WeaponToOwner";

    public static final String FUNC_TRANSFERFROM = "transferFrom";

    public static final String FUNC_CHANGECREDS = "changeCreds";

    public static final String FUNC_WITHDRAW = "withdraw";

    public static final String FUNC_WEAPONS = "weapons";

    public static final String FUNC_OWNEROF = "ownerOf";

    public static final String FUNC_BALANCEOF = "balanceOf";

    public static final String FUNC_RENOUNCEOWNERSHIP = "renounceOwnership";

    public static final String FUNC_OWNER = "owner";

    public static final String FUNC_ISOWNER = "isOwner";

    public static final String FUNC_GETWEAPON = "getWeapon";

    public static final String FUNC_CHANGENAME = "changeName";

    public static final String FUNC__CREATEWEAPON = "_createWeapon";

    public static final String FUNC_SETLEVELUPFEE = "setLevelUpFee";

    public static final String FUNC_TRANSFEROWNERSHIP = "transferOwnership";

    public static final Event NEWWEAPON_EVENT = new Event("NewWeapon", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}, new TypeReference<Utf8String>() {}, new TypeReference<Uint256>() {}));
    ;

    public static final Event TRANSFER_EVENT = new Event("Transfer", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}, new TypeReference<Uint256>(true) {}));
    ;

    public static final Event APPROVAL_EVENT = new Event("Approval", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}, new TypeReference<Uint256>(true) {}));
    ;

    public static final Event OWNERSHIPTRANSFERRED_EVENT = new Event("OwnershipTransferred", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}));
    ;

    @Deprecated
    protected WeaponOwnership(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    protected WeaponOwnership(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, credentials, contractGasProvider);
    }

    @Deprecated
    protected WeaponOwnership(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    protected WeaponOwnership(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public RemoteCall<List> getWeaponByOwner(String _owner) {
        final Function function = new Function(FUNC_GETWEAPONBYOWNER, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_owner)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<DynamicArray<Uint256>>() {}));
        return new RemoteCall<List>(
                new Callable<List>() {
                    @Override
                    @SuppressWarnings("unchecked")
                    public List call() throws Exception {
                        List<Type> result = (List<Type>) executeCallSingleValueReturn(function, List.class);
                        return convertToNative(result);
                    }
                });
    }

    public RemoteCall<TransactionReceipt> approve(String _approved, BigInteger _tokenId, BigInteger weiValue) {
        final Function function = new Function(
                FUNC_APPROVE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_approved), 
                new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function, weiValue);
    }

    public RemoteCall<TransactionReceipt> levelUp(BigInteger _weaponId, BigInteger weiValue) {
        final Function function = new Function(
                FUNC_LEVELUP, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function, weiValue);
    }

    public RemoteCall<String> WeaponToOwner(BigInteger param0) {
        final Function function = new Function(FUNC_WEAPONTOOWNER, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(param0)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<TransactionReceipt> transferFrom(String _from, String _to, BigInteger _tokenId, BigInteger weiValue) {
        final Function function = new Function(
                FUNC_TRANSFERFROM, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_from), 
                new org.web3j.abi.datatypes.Address(_to), 
                new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function, weiValue);
    }

    public RemoteCall<TransactionReceipt> changeCreds(BigInteger _weaponId, BigInteger _newCreds) {
        final Function function = new Function(
                FUNC_CHANGECREDS, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId), 
                new org.web3j.abi.datatypes.generated.Uint256(_newCreds)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> withdraw() {
        final Function function = new Function(
                FUNC_WITHDRAW, 
                Arrays.<Type>asList(), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>> weapons(BigInteger param0) {
        final Function function = new Function(FUNC_WEAPONS, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(param0)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}, new TypeReference<Uint256>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint256>() {}, new TypeReference<Uint16>() {}, new TypeReference<Uint16>() {}));
        return new RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>(
                new Callable<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>() {
                    @Override
                    public Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger> call() throws Exception {
                        List<Type> results = executeCallMultipleValueReturn(function);
                        return new Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>(
                                (String) results.get(0).getValue(), 
                                (BigInteger) results.get(1).getValue(), 
                                (BigInteger) results.get(2).getValue(), 
                                (BigInteger) results.get(3).getValue(), 
                                (BigInteger) results.get(4).getValue(), 
                                (BigInteger) results.get(5).getValue(), 
                                (BigInteger) results.get(6).getValue());
                    }
                });
    }

    public RemoteCall<String> ownerOf(BigInteger _tokenId) {
        final Function function = new Function(FUNC_OWNEROF, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<BigInteger> balanceOf(String _owner) {
        final Function function = new Function(FUNC_BALANCEOF, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_owner)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<TransactionReceipt> renounceOwnership() {
        final Function function = new Function(
                FUNC_RENOUNCEOWNERSHIP, 
                Arrays.<Type>asList(), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<String> owner() {
        final Function function = new Function(FUNC_OWNER, 
                Arrays.<Type>asList(), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<Boolean> isOwner() {
        final Function function = new Function(FUNC_ISOWNER, 
                Arrays.<Type>asList(), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Bool>() {}));
        return executeRemoteCallSingleValueReturn(function, Boolean.class);
    }

    public RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>> getWeapon(BigInteger _id) {
        final Function function = new Function(FUNC_GETWEAPON, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_id)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}, new TypeReference<Uint256>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint256>() {}, new TypeReference<Uint16>() {}, new TypeReference<Uint16>() {}));
        return new RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>(
                new Callable<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>() {
                    @Override
                    public Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger> call() throws Exception {
                        List<Type> results = executeCallMultipleValueReturn(function);
                        return new Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>(
                                (String) results.get(0).getValue(), 
                                (BigInteger) results.get(1).getValue(), 
                                (BigInteger) results.get(2).getValue(), 
                                (BigInteger) results.get(3).getValue(), 
                                (BigInteger) results.get(4).getValue(), 
                                (BigInteger) results.get(5).getValue(), 
                                (BigInteger) results.get(6).getValue());
                    }
                });
    }

    public RemoteCall<TransactionReceipt> changeName(BigInteger _weaponId, String _newName) {
        final Function function = new Function(
                FUNC_CHANGENAME, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId), 
                new org.web3j.abi.datatypes.Utf8String(_newName)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> _createWeapon(String _name, BigInteger _wepType) {
        final Function function = new Function(
                FUNC__CREATEWEAPON, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Utf8String(_name), 
                new org.web3j.abi.datatypes.generated.Uint256(_wepType)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> setLevelUpFee(BigInteger _fee) {
        final Function function = new Function(
                FUNC_SETLEVELUPFEE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_fee)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> transferOwnership(String newOwner) {
        final Function function = new Function(
                FUNC_TRANSFEROWNERSHIP, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(newOwner)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public List<NewWeaponEventResponse> getNewWeaponEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(NEWWEAPON_EVENT, transactionReceipt);
        ArrayList<NewWeaponEventResponse> responses = new ArrayList<NewWeaponEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            NewWeaponEventResponse typedResponse = new NewWeaponEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse.weaponId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
            typedResponse.name = (String) eventValues.getNonIndexedValues().get(1).getValue();
            typedResponse.wepType = (BigInteger) eventValues.getNonIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<NewWeaponEventResponse> newWeaponEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, NewWeaponEventResponse>() {
            @Override
            public NewWeaponEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(NEWWEAPON_EVENT, log);
                NewWeaponEventResponse typedResponse = new NewWeaponEventResponse();
                typedResponse.log = log;
                typedResponse.weaponId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
                typedResponse.name = (String) eventValues.getNonIndexedValues().get(1).getValue();
                typedResponse.wepType = (BigInteger) eventValues.getNonIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<NewWeaponEventResponse> newWeaponEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(NEWWEAPON_EVENT));
        return newWeaponEventFlowable(filter);
    }

    public List<TransferEventResponse> getTransferEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(TRANSFER_EVENT, transactionReceipt);
        ArrayList<TransferEventResponse> responses = new ArrayList<TransferEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            TransferEventResponse typedResponse = new TransferEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._from = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse._to = (String) eventValues.getIndexedValues().get(1).getValue();
            typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<TransferEventResponse> transferEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, TransferEventResponse>() {
            @Override
            public TransferEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(TRANSFER_EVENT, log);
                TransferEventResponse typedResponse = new TransferEventResponse();
                typedResponse.log = log;
                typedResponse._from = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse._to = (String) eventValues.getIndexedValues().get(1).getValue();
                typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<TransferEventResponse> transferEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(TRANSFER_EVENT));
        return transferEventFlowable(filter);
    }

    public List<ApprovalEventResponse> getApprovalEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(APPROVAL_EVENT, transactionReceipt);
        ArrayList<ApprovalEventResponse> responses = new ArrayList<ApprovalEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            ApprovalEventResponse typedResponse = new ApprovalEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._owner = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse._approved = (String) eventValues.getIndexedValues().get(1).getValue();
            typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<ApprovalEventResponse> approvalEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, ApprovalEventResponse>() {
            @Override
            public ApprovalEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(APPROVAL_EVENT, log);
                ApprovalEventResponse typedResponse = new ApprovalEventResponse();
                typedResponse.log = log;
                typedResponse._owner = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse._approved = (String) eventValues.getIndexedValues().get(1).getValue();
                typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<ApprovalEventResponse> approvalEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(APPROVAL_EVENT));
        return approvalEventFlowable(filter);
    }

    public List<OwnershipTransferredEventResponse> getOwnershipTransferredEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(OWNERSHIPTRANSFERRED_EVENT, transactionReceipt);
        ArrayList<OwnershipTransferredEventResponse> responses = new ArrayList<OwnershipTransferredEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            OwnershipTransferredEventResponse typedResponse = new OwnershipTransferredEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse.previousOwner = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse.newOwner = (String) eventValues.getIndexedValues().get(1).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<OwnershipTransferredEventResponse> ownershipTransferredEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, OwnershipTransferredEventResponse>() {
            @Override
            public OwnershipTransferredEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(OWNERSHIPTRANSFERRED_EVENT, log);
                OwnershipTransferredEventResponse typedResponse = new OwnershipTransferredEventResponse();
                typedResponse.log = log;
                typedResponse.previousOwner = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse.newOwner = (String) eventValues.getIndexedValues().get(1).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<OwnershipTransferredEventResponse> ownershipTransferredEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(OWNERSHIPTRANSFERRED_EVENT));
        return ownershipTransferredEventFlowable(filter);
    }

    @Deprecated
    public static WeaponOwnership load(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return new WeaponOwnership(contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    @Deprecated
    public static WeaponOwnership load(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return new WeaponOwnership(contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    public static WeaponOwnership load(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return new WeaponOwnership(contractAddress, web3j, credentials, contractGasProvider);
    }

    public static WeaponOwnership load(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return new WeaponOwnership(contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public static RemoteCall<WeaponOwnership> deploy(Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(WeaponOwnership.class, web3j, credentials, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<WeaponOwnership> deploy(Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(WeaponOwnership.class, web3j, credentials, gasPrice, gasLimit, BINARY, "");
    }

    public static RemoteCall<WeaponOwnership> deploy(Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(WeaponOwnership.class, web3j, transactionManager, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<WeaponOwnership> deploy(Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(WeaponOwnership.class, web3j, transactionManager, gasPrice, gasLimit, BINARY, "");
    }

    public static class NewWeaponEventResponse {
        public Log log;

        public BigInteger weaponId;

        public String name;

        public BigInteger wepType;
    }

    public static class TransferEventResponse {
        public Log log;

        public String _from;

        public String _to;

        public BigInteger _tokenId;
    }

    public static class ApprovalEventResponse {
        public Log log;

        public String _owner;

        public String _approved;

        public BigInteger _tokenId;
    }

    public static class OwnershipTransferredEventResponse {
        public Log log;

        public String previousOwner;

        public String newOwner;
    }
}
